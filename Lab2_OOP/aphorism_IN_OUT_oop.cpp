#include <iostream>
#include "aphorism_oop.h"

using namespace std;
namespace collection_of_wisdom_oop {
	void aphorism::InData(ifstream &ifst) {
		string Line; //Временное решение на случай переполнения
		getline(ifst, Line); //Строка заносится в Line
		if (Line.length() < 50) { //Проверка на переполнение - если длина Line < 50
			strcpy_s(this->author, 50, Line.c_str());
		}
		else {
			Line.resize(49);
			strcpy_s(this->author, 50, Line.c_str());
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
} // end collection_of_wisdom_oop namespace