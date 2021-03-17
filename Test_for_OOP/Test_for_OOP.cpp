#include "pch.h"
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
			container c = container();
			c.In(ifst);
			//char *exp_overbuf = c[0]->expression;
			//Assert::AreEqual(real_len, 1);//OK
			c.Clear();
		}
	};
}
