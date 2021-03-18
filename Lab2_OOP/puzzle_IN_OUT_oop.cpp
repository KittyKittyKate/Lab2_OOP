#include <iostream>
#include "puzzle_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {

	void puzzle::InData(ifstream &ifst) {
		string Line; //Временное решение на случай переполнения
		getline(ifst, Line); //Строка заносится в Line
		if (Line.length() < 20) { //Проверка на переполнение - если длина Line < 20
			strcpy_s(this->answer, 20, Line.c_str());
		}
		else {
			Line.resize(19);
			strcpy_s(this->answer, 20, Line.c_str());
		}
		Line.clear();
	}
	
	void puzzle::Out(ofstream &ofst) {
		ofst << "Answer: " << this->answer;
	}
} // end collection_of_wisdom_oop namespace