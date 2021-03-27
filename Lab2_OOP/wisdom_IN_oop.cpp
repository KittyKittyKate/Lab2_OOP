#include "wisdom_oop.h"
// Необходима подключить информацию обо всех имеющихся
// геометрических фигурах
#include "aphorism_oop.h"
#include "proverb_oop.h"
#include "puzzle_oop.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include "limits.h"

using namespace std;
namespace collection_of_wisdom_oop {
	// Ввод параметров обобщенной фигуры
	wisdom* wisdom::In(ifstream &ifst) {
		wisdom *sp;
		int k = 0;

		string Full_Line;//число
		getline(ifst, Full_Line);
		string Data = FindData("Type of wisdom:", Full_Line);
		if (Data.compare("error") != 0 && Data.compare("empty") != 0) {// если НЕ "ошибка"(данные не введены) И НЕ "пусто"(пустая строка)
			try {
				//static_cast<int>(stoi(Data, 0, 10));
				if (isdigit(Data[0]) == 0) {
					throw Data;//если Data - строка, а не число
				}
				if (static_cast<int>(stoi(Data, 0, 10)) > INT_MAX) {// если переполнение
					cout << "ERROR: overflow (Type of wisdom > INT_MAX)." << endl;
				}
				else if (static_cast<int>(stoi(Data, 0, 10)) < INT_MIN) {// если слишком маленькое значение
					cout << "ERROR: overflow (Type of wisdom < INT_MIN)." << endl;
				}
				else {//если с типом все хорошо
					k = static_cast<int>(stoi(Data, 0, 10));
				}
			}
			catch (string Data) {
				cout << "ERROR: 'Type of wisdom' should be int ('Type of wisdom' == " << Data << ")." << endl;
				k = 0;
			}

		}
		else if (Data.compare("empty") == 0) { // если "пусто"(пустая строка)
			return 0;
		}

		switch (k) {
		case 1:
			sp = new aphorism;
			break;
		case 2:
			sp = new proverb;
			break;
		case 3:
			sp = new puzzle;
			break;
		default: //Если неправильный тип мудрости, то пропускаем три строки(мудрость не создается)
			Junk(ifst);
			return 0;
		}

		bool Exit_Flag = true;

		do {// ищем Expression
			getline(ifst, Full_Line); //Строка заносится в Full_Line
			Data = FindData("Expression:", Full_Line);
			Exit_Flag = true;

			if (Data.compare("error") == 0) { //если выражения нет, то выбрасываем послед. строки и переходим к новой мудрости
				delete[] sp;
				string Junk; //для мусора
				getline(ifst, Junk); //Здесь - уникальная характеристика
				getline(ifst, Junk); //Здесь - оценка
				Junk.clear();
				return 0;
			}
			else if (Data.compare("empty") == 0) {//если пустая строка
				Exit_Flag = false; // если false, то продолжаем цикл
			}

		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return 0;
		}
		else { //если не конец файла
			*sp->expression = CheckForOverflow(Data, sp->expression, ifst, 100);// проверка выражения на переполнение, занесение выражения в expression
		}

		if (sp->InData(ifst) == "error") {
			return 0;
		}

		if (ifst.eof()) {//если конец файла, то выход
			return 0;
		}//иначе продолжаем

		do {//ищем оценку
			getline(ifst, Full_Line);
			Data = FindData("Rate:", Full_Line);

			if (Data.compare("error") != 0 && Data.compare("empty") != 0) {// если НЕ "ошибка"(данные не введены) И НЕ "пусто"(пустая строка)
				try {
					if (isdigit(Data[0]) == 0) {
						throw Data;//если Data - строка, а не число
					}
					if (static_cast<int>(stoi(Data, 0, 10)) > 10) {// если переполнение
						delete[] sp;
						cout << "ERROR: unexpected value (Rate > 10)." << endl;
						return 0;
					}
					else if (static_cast<int>(stoi(Data, 0, 10)) < 0) {// если слишком маленькое значение
						delete[] sp;
						cout << "ERROR: unexpected value (Rate < 10)." << endl;
						return 0;
					}
					else {//если с оценкой все хорошо
						sp->rate = static_cast<int>(stoi(Data, 0, 10));
						//Exit_Flag = true;
						return sp;
					}
				}
				catch (string Data) {
					cout << "ERROR: 'Rate' should be int ('Rate' == " << Data << ")." << endl;
					delete[] sp;
					return 0;
				}

			}
			else if (Data.compare("empty") == 0) { // если "пусто"(пустая строка), то идем на следующую строку
				Exit_Flag = false;
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return 0;
		}

		Full_Line.clear();
	}
	string wisdom::FindData(const string &Text, string &Line)
	{
		string Data;
		if (Line.compare("") == 0) {
			cout << "Empty line." << endl;
			return "empty";
		}
		try {
			int Position = static_cast<int>(Line.find(Text));
			if (Position != 0) {
				throw Position;
			}

			try {//если  position == 0
				int Difference = static_cast<int>(Line.length()) - static_cast<int>(Text.length());
				if (Difference == 0) {
					throw Text;
				}
				Data = Line.substr(static_cast<int>(Text.length()), Difference);
				return Data;
			}
			catch (string s) {
				cout << "ERROR: the data is empty (" << s << ")." << endl;
				return "error";
			}
		}
		catch (int Position) {
			if (Position != -1) {
				cout << "WARNING: unexpected format of data (" << Line.substr(0, Position + static_cast<int>(Text.length())) << ")." << endl;
				Data = Line.substr(Position + static_cast<int>(Text.length()), static_cast<int>(Line.length()) - 1);
				return Data;
			}
			else if (Position == -1) {//если данные введены неправильно
				cout << "ERROR: incorrect data format." << endl;
				return "error";
			}
		}
	}
	void wisdom::Junk(ifstream &ifst)
	{
		string Junk; //для мусора
		getline(ifst, Junk); //Здесь - выражение
		getline(ifst, Junk); //Здесь - уникальная характеристика
		getline(ifst, Junk); //Здесь - оценка
		Junk.clear();
	}
	char& wisdom::CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len)
	{
		if (static_cast<int>(Data.length()) < Len) { //Проверка на переполнение - если длина данных < Len, то просто заносим выражение в переменную
			strcpy_s(char_text, Len, Data.c_str());
			return *char_text;
		}
		else { //иначе придется отсечь лишнее
			Data.resize(Len - 1);
			strcpy_s(char_text, Len, Data.c_str());
			return *char_text;
		}
	}
	bool wisdom::Compare(wisdom &other) {
		return Count_Comma() > other.Count_Comma(); 
	}
	int wisdom::Count_Comma() {
		int comma = 0;
		int i = 0;
		while (this->expression[i] != '\0')
		{
			if (this->expression[i] == ',') {
				comma++;
			}
			i++;
		}
		return comma;
	}
	void wisdom::OutAphorism(ofstream &ofst, wisdom *sp) {
		ofst << endl; 
	}

} // end collection_of_wisdom_oop namespace