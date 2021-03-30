#include "wisdom_oop.h"
#include "aphorism_oop.h"
#include "proverb_oop.h"
#include "puzzle_oop.h"
#include <iostream>
#include <string>
#include "limits.h"

using namespace std;

namespace collection_of_wisdom_oop {
	wisdom* wisdom::In(ifstream &ifst) {
		wisdom *sp;
		int k = 0;
		string Full_Line;
		getline(ifst, Full_Line);	//Считываем строку в Full_Line.
		string Data = FindData("Type of wisdom:", Full_Line);

		if (Data.compare("error") != 0 && Data.compare("empty") != 0) {	//Если FindData не вернула "error" или "empty".
			try {
				if (isdigit(Data[0]) == 0) {
					throw Data;	//Исключение: Data - строка, а не число
				}

				if (static_cast<int>(stoi(Data, 0, 10)) > INT_MAX) {	//Если Data > маск. значения, которое может иметь int.
					cout << "ERROR: overflow (Type of wisdom > INT_MAX)." << endl;
				}
				else if (static_cast<int>(stoi(Data, 0, 10)) < INT_MIN) {	//Если Data < мин. значения, которое может иметь int.
					cout << "ERROR: overflow (Type of wisdom < INT_MIN)." << endl;
				}
				else {	//Если INT_MIN < Data < INT_MAX.
					k = static_cast<int>(stoi(Data, 0, 10));
				}
			}
			catch (string Data) {	//Сообщаем об ошибке.
				cout << "ERROR: 'Type of wisdom' should be int ('Type of wisdom' == " << Data << ")." << endl;
				k = 0;
			}
		}
		else if (Data.compare("empty") == 0) {	//Если FindData вернула "empty", то выход из функции.
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
		default:	//Все, кроме 1, 2, 3, попадает сюда (неправильный тип мудрости). Пропускаем три строки. Выход из функции.
			Junk(ifst);
			return 0;
		}
		bool Exit_Flag = true;
		//Здесь обработка поля "Expression:".
		do {
			getline(ifst, Full_Line);	//Строка заносится в Full_Line.
			Data = FindData("Expression:", Full_Line);
			Exit_Flag = true;

			if (Data.compare("error") == 0) {	//Если FindData вернула "error" (не нашла подстроку "Expression:"), то пропускаем последующие строки.
				delete[] sp;
				string Junk; //Для мусора.
				getline(ifst, Junk); //Здесь - уникальная характеристика.
				getline(ifst, Junk); //Здесь - оценка.
				Junk.clear();
				return 0;
			}
			else if (Data.compare("empty") == 0) {//Если FindData вернула "empty".
				Exit_Flag = false; 
			}

		} while ((ifst.eof() == false) && (Exit_Flag == false)); //Пока не конец файла и Exit_Flag == false - цикл будет продолжаться.

		if (ifst.eof()) {//Сообщаем о конце файла.
			cout << "INFORMATION: the end of file." << endl;
			return 0;
		}
		else { //Если конец файла еще не наступил.
			*sp->expression = CheckForOverflow(Data, sp->expression, ifst, 100);//Здесь происходит проверка на переполнение и занесение подстроки в expression.
		}

		if (sp->InData(ifst) == "error") {// Если InData возвращает "error", то мудрость не занесется в контейнер, произойдет выход из функции.
			delete[] sp;
			return 0;
		}

		if (ifst.eof()) {//Однако выход из InData может произойти и по причине конца файла.
			return 0;
		}
		//Здесь обработка поля "Rate:".
		do {
			getline(ifst, Full_Line);
			Data = FindData("Rate:", Full_Line);//Строка заносится в Full_Line.

			if (Data.compare("error") != 0 && Data.compare("empty") != 0) {//Если FindData не вернула "error" или "empty".
				try {
					if (isdigit(Data[0]) == 0) {
						throw Data; //Исключение: Data - строка, а не число.
					}

					if (static_cast<int>(stoi(Data, 0, 10)) > 10) {//Если Data > 10.
						delete[] sp;
						cout << "ERROR: unexpected value (Rate > 10)." << endl;
						return 0;
					}
					else if (static_cast<int>(stoi(Data, 0, 10)) < 0) {//Если Data < 0.
						delete[] sp;
						cout << "ERROR: unexpected value (Rate < 0)." << endl;
						return 0;
					}
					else {//Если 0 < Data < 10.
						sp->rate = static_cast<int>(stoi(Data, 0, 10));
						return sp;//Как только получили оценку мудрости, можно сразу вернуть мудрость.
					}
				}
				catch (string Data) {//Сообщаем, что поле "Rate:" - должно содержать число.
					cout << "ERROR: 'Rate' should be int ('Rate' == " << Data << ")." << endl;
					delete[] sp;
					return 0;
				}

			}
			else if (Data.compare("empty") == 0) { //Если FindData вернула "empty".
				Exit_Flag = false;
			}
			else if (Data.compare("error") == 0) { //Если FindData вернула "error".
				cout << "ERROR: misprint in field 'Rate:'." << endl;
				delete[] sp;
				return 0;
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));//Пока не конец файла и Exit_Flag == false - цикл будет продолжаться.

		if (ifst.eof()) {//Сообщаем о конце файла.
			cout << "INFORMATION: the end of file." << endl;
			return 0;
		}

		Full_Line.clear();//Чистим Full_Line.
	}
	string wisdom::FindData(const string &Text, string &Line) {
		string Data;

		if (Line.compare("") == 0) {//Если в строке ничего нет.
			cout << "Empty line." << endl;
			return "empty";
		}
		try {//Здесь ищем подстроку.
			int Position = static_cast<int>(Line.find(Text));

			if (Position != 0) {
				throw Position;
			}

			try {//Если  Position == 0 (ничего не сдвинуто).
				int Difference = static_cast<int>(Line.length()) - static_cast<int>(Text.length());

				if (Difference == 0) {
					throw Text;
				}

				Data = Line.substr(static_cast<int>(Text.length()), Difference);
				return Data;
			}
			catch (string s) {//Если в поле отсутствуют данные.
				cout << "ERROR: the data is empty (" << s << ")." << endl;
				return "error";
			}
		}
		catch (int Position) {
			if (Position != -1) {//В случае, если поля сдвинуты, данные все равно считываются.
				cout << "WARNING: unexpected format of data (" << Line.substr(0, Position + static_cast<int>(Text.length())) << ")." << endl;
				Data = Line.substr(Position + static_cast<int>(Text.length()), static_cast<int>(Line.length()) - 1);
				return Data;
			}
			else if (Position == -1) {//В случае, если данные введены неправильно.
				cout << "ERROR: incorrect data format." << endl;
				return "error";
			}
		}
	}
	void wisdom::Junk(ifstream &ifst) {
		string Junk; //Для мусора.
		getline(ifst, Junk); //Здесь - выражение.
		getline(ifst, Junk); //Здесь - уникальная характеристика.
		getline(ifst, Junk); //Здесь - оценка.
		Junk.clear();
	}
	char& wisdom::CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len) {
		if (static_cast<int>(Data.length()) < Len) { //Проверка на переполнение: Если длина данных < Len, то просто заносим подстроку в переменную.
			strcpy_s(char_text, Len, Data.c_str());
			return *char_text;
		}
		else { //Если длина данных > Len, то придется отсечь лишнее и заполнить переменную.
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

		while (this->expression[i] != '\0') {
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
}