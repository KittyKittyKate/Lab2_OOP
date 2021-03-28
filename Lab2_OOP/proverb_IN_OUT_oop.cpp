#include <iostream>
#include "proverb_oop.h"
#include <string>

using namespace std;
namespace collection_of_wisdom_oop {
	
	string proverb::InData(ifstream &ifst) {
		string Full_Line;
		string Data;
		bool Exit_Flag = true;

		do {
			getline(ifst, Full_Line);//строка со страной
			Data = FindData("Country:", Full_Line);//В Data будет страна
			Exit_Flag = true;

			if (Data.compare("error") == 0) { //если страны нет, то выбрасываем послед. строки и переходим к новой мудрости
				string Junk; //для мусора
				getline(ifst, Junk); //Здесь - оценка
				Junk.clear();
				return "error";
			}
			else if (Data.compare("empty") == 0) {//если пустая строка
				Exit_Flag = false; // если false, то продолжаем цикл
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return "";
		}
		else { //если не конец файла, то проверяем на переполнение
			this->CheckForOverflow(Data, this->country, ifst, 50);
			Data.clear();
			Full_Line.clear();
			return "";
		}
	}
	
	void proverb::Out(ofstream &ofst) {
		ofst << this->country;
	}
} // end collection_of_wisdom_oop namespace