#include <iostream>
#include "aphorism_oop.h"
#include <string>

using namespace std;

namespace collection_of_wisdom_oop {
	string aphorism::InData(ifstream &ifst) {
		string Full_Line;
		string Data;
		bool Exit_Flag = true;

		do {
			getline(ifst, Full_Line);
			Data = FindData("Author:", Full_Line);	//В Data будет автор.
			Exit_Flag = true;

			if (Data.compare("error") == 0) { //Если автора нет, то выбрасываем последующие строки и переходим к новой мудрости.
				string Junk;	//Для мусора.
				getline(ifst, Junk);	//Здесь - оценка.
				Junk.clear();
				return "error";
			}
			else if (Data.compare("empty") == 0) {	//Если пустая строка.
				Exit_Flag = false; //Если false, то идем по циклу дальше.
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return "";
		}
		else { //Если не конец файла, то проверяем на переполнение.
			this->CheckForOverflow(Data, this->author, ifst, 50);
			Data.clear();
			Full_Line.clear();
			return "";
		}
	}
	void aphorism::Out(ofstream &ofst) {
		ofst << this->author;
	}
	void aphorism::OutAphorism(ofstream &ofst, wisdom *sp) {
		ofst << "'" << sp->expression << "' - ";
		Out(ofst);
		ofst << ". My rate: " << sp->rate << endl;
		ofst << "Count of comma: " << sp->Count_Comma() << endl;
	}
}