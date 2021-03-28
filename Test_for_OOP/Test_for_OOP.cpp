﻿#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Lab2_OOP/container_oop.h"
#include "../Lab2_OOP/container_CONSTR_oop.cpp"
#include "../Lab2_OOP/container_IN_OUT_oop.cpp"
#include "../Lab2_OOP/wisdom_oop.h"
#include "../Lab2_OOP/wisdom_IN_oop.cpp"
#include "../Lab2_OOP/aphorism_oop.h"
#include "../Lab2_OOP/puzzle_oop.h"
#include "../Lab2_OOP/proverb_oop.h"
#include "../Lab2_OOP/proverb_IN_OUT_oop.cpp"
#include "../Lab2_OOP/aphorism_IN_OUT_oop.cpp"
#include "../Lab2_OOP/puzzle_IN_OUT_oop.cpp"

using namespace collection_of_wisdom_oop;
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int Difference(ifstream &ifst_1, ifstream &ifst_2);

namespace TestforOOP
{

	TEST_CLASS(TestforOOP)
	{
	public:

		TEST_METHOD(Container_In_7) //Проверка функции In для контейнера
		{
			ifstream ifst("in_7.txt"); //В файле 7 мудростей
			container c = container();
			c.In(ifst);
			int real_len = c.length;
			Assert::AreEqual(real_len, 7);//OK
			c.Clear();
		}
		TEST_METHOD(Container_In_0) //Проверка функции In для контейнера
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			container c = container();
			c.In(ifst);
			int real_len = c.length;
			Assert::AreEqual(real_len, 0);//OK
			c.Clear();
		}
		TEST_METHOD(Wisdom_In_7) //Проверка функции In для класса wisdom
		{
			ifstream ifst("in_7_with_incorrect_keys.txt"); //В файле 7 мудростей, 3 мудрости с неправильными ключами
			container c = container();
			c.In(ifst);
			int real_len = c.length;
			Assert::AreEqual(real_len, 4); //OK
			c.Clear();
		}
		TEST_METHOD(Container_Sort_7) //Проверка функции Sort для контейнера
		{
			ifstream ifst("in_7.txt"); //В файле 7 мудростей
			ofstream ofst("out_7.txt");
			container c = container();
			c.In(ifst);
			c.Sort(); // ОК, сортировка прошла как обычно
			c.Out(ofst);
			int real_len = c.length;
			Assert::AreEqual(real_len, 7); //OK
			c.Clear();
		}
		TEST_METHOD(Container_Sort_0) //Проверка функции Sort для пустого контейнера
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			ofstream ofst("out_0.txt");
			container c = container();
			c.In(ifst);
			c.Sort(); //OK, сортировка не произошла
			c.Out(ofst); //В выходном файле "Container contents 0 elements."
			int real_len = c.length;
			Assert::AreEqual(real_len, 0); //OK
			c.Clear();
		}
		TEST_METHOD(Container_Sort_1) //Проверка функции Sort для контейнера с одним элементом
		{
			ifstream ifst("in_1.txt"); //В файле один элемент
			ofstream ofst("out_1.txt");
			container c = container();
			c.In(ifst);
			c.Sort(); //OK, сортировка не произошла
			c.Out(ofst); //В выходном файле "Container contents 1 elements."
			int real_len = c.length;
			Assert::AreEqual(real_len, 1); //OK
			c.Clear();
		}
		TEST_METHOD(Container_Sort_2) //Проверка функции Sort для контейнера с двумя элементами
		{
			ifstream ifst("in_2.txt"); //В файле два элемента
			ofstream ofst("out_2.txt");
			container c = container();
			c.In(ifst);
			c.Sort(); //OK, сортировка ведет себя адекватно 
			c.Out(ofst); //В выходном файле "Container contents 2 elements."
			int real_len = c.length;
			Assert::AreEqual(real_len, 2); //OK
			c.Clear();
		}
		TEST_METHOD(Container_OutAphorisms_0) //Проверка функции OutAphorisms для пустого контейнера
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			ofstream ofst("out_0.txt");
			container c = container();
			c.In(ifst);
			c.OutAphorisms(ofst); //В выходном файле "Only aphorisms."
			int real_len = c.length;
			Assert::AreEqual(real_len, 0); //OK
			c.Clear();
		}
		TEST_METHOD(Container_OutAphorisms_without_aphors) //Проверка функции OutAphorisms контейнера без афоризмов
		{
			ifstream ifst("in_5_without_aphors.txt"); //В файле 5 мудростей
			ofstream ofst("out_5_without_aphors.txt");
			container c = container();
			c.In(ifst);
			c.OutAphorisms(ofst); //В выходном файле "Only aphorisms."
			int real_len = c.length;
			Assert::AreEqual(real_len, 5); //OK
			c.Clear();
		}
		TEST_METHOD(Wisdom_InData_OverBuf) //Проверка функции InData на поведение в случае переполнения
		{
			ifstream ifst("in_1_overbuf.txt"); //В файле один афоризм с выражением > 100 символов
			ofstream ofst("out_1_overbuf.txt");
			ifstream ifst_IDEAL("in_1_overbuf_IDEAL.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_1_overbuf.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			c.Clear();
		}
		TEST_METHOD(Wisdom_CountOfComma_0) //Проверка функции CountOfComma в случае 0 запятых
		{
			ifstream ifst("in_0_commas.txt"); //В выражении нет запятых
			ofstream ofst("out_0_commas.txt");
			ifstream ifst_IDEAL("out_0_commas_IDEAL.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_0_commas.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			c.Clear();
		}
		TEST_METHOD(Wisdom_CountOfComma_1) //Проверка функции CountOfComma в случае 1 запятых
		{
			ifstream ifst("in_1_comma.txt"); //В выражении 1 запятая
			ofstream ofst("out_1_comma.txt");
			ifstream ifst_IDEAL("out_1_comma_IDEAL.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_1_comma.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			c.Clear();
		}
		TEST_METHOD(Wisdom_CountOfComma_5) //Проверка функции CountOfComma в случае 5 запятых
		{
			ifstream ifst("in_5_commas.txt"); //В выражении 5 запятых
			ofstream ofst("out_5_commas.txt");
			ifstream ifst_IDEAL("out_5_commas_IDEAL.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_5_commas.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			c.Clear();
		}
		TEST_METHOD(Container_Clean_0) //Проверка очистки контейнера при отсутствии элементов
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			//ofstream ofst("out_0.txt");
			//ifstream ifst_IDEAL("out_0_IDEAL.txt");
			container c = container();
			c.In(ifst);
			//c.Out(ofst);
			//тут сравнение двух файлов
			//ifstream ifst_to_cmp("out_0.txt");
			//
			c.Clear();//OK, цикл не начинался
			Assert::AreEqual(c.length, 0); //OK
		}
		TEST_METHOD(A_P_P_OverBuf) //Проверка функций InData трех подклассов на поведение в случае переполнения
		{
			ifstream ifst("in_3_overbuf.txt"); //В файле 3 мудрости с переполненными уник. хар-ми 
			ofstream ofst("out_3_overbuf.txt");
			ifstream ifst_IDEAL("out_3_overbuf_IDEAL.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_3_overbuf.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK 
			c.Clear();
		}
		TEST_METHOD(A_P_P_OverBuf_For_Int) //Проверка трех подклассов на поведение в случае выхода численных значений за пределы
		{
			ifstream ifst("in_3_overbuf_int.txt"); //В файле 3 мудрости с rate > 10, rate < 0 и 0 < rate <10
			container c = container();
			c.In(ifst);
			Assert::AreEqual(c.length, 1); //OK, на входе - 3, на выход прошла только 1 мудрость
			c.Clear();
		}
		TEST_METHOD(Wrong_Wisdom_Type_Of_Wisdom) //Проверка поведения в случае неверного формата ввода (отсутствует строка "Type of wisdom:")
		{
			ifstream ifst("in_wr_type_of_w.txt"); //В файле 1 мудрость без "Type of wisdom:"
			ofstream ofst("out_wr_type_of_w.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			Assert::AreEqual(c.length, 0); //OK, отсутствие "Type of wisdom:" считается ошибкой, мудрость не заносится в контейнер
			c.Clear();
		}
		TEST_METHOD(Wrong_Wisdom_Type_Of_Wisdom_Empty) //Проверка поведения в случае неверного формата ввода (отсутствуют данные в "Type of wisdom:")
		{
			ifstream ifst("in_wr_type_of_w_empty.txt"); //В файле 1 мудрость без данных в "Type of wisdom:"
			ofstream ofst("out_wr_type_of_w_empty.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			Assert::AreEqual(c.length, 0); //OK, отсутствие данных в "Type of wisdom:" считается ошибкой, мудрость не заносится в контейнер
			c.Clear();
		}
		TEST_METHOD(Unexpected_Fields) //Проверка поведения в случае неожидаемого формата ввода (поля сдвинуты)
		{
			ifstream ifst("in_unexp_fields.txt"); //В файле 1 мудрость со сдвинутыми полями
			ofstream ofst("out_unexp_fields.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			Assert::AreEqual(c.length, 1); //OK, мудрость записана
			c.Clear();
		}
		TEST_METHOD(Incorrect_Fields) //Проверка поведения в случае ошибок в полях (были исправления в коде)
		{
			ifstream ifst("in_incorrect_fields.txt"); //В файле 5 мудростей, 4 из них с ошибками в полях
			ofstream ofst("out_incorrect_fields.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			Assert::AreEqual(c.length, 1); //OK, 1 мудрость записана
			c.Clear();
		}
		TEST_METHOD(Empty_Lines_In_Wisdom) //Проверка поведения при наличии пустых строк между полями
		{
			ifstream ifst("in_empty_lines.txt"); //В файле 5 мудростей с пустыми строками между полями
			ofstream ofst("out_empty_lines.txt");
			container c = container();
			c.In(ifst);
			c.Out(ofst);
			Assert::AreEqual(c.length, 5); //OK, 5 мудростей записано
			c.Clear();
		}
	};
}

int Difference(ifstream & ifst_1, ifstream & ifst_2)
{
	char ch_1 = '0';
	char ch_2 = '0';
	
	while (ifst_1.get(ch_1) && ifst_2.get(ch_2)) {
		if (ch_1 != ch_2)
		{
			return 0;
		}
	}
	return 1;
}
