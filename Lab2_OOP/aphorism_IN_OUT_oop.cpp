#include <iostream>
#include "aphorism_oop.h"

using namespace std;
namespace collection_of_wisdom_oop {
	// Ввод параметров прямоугольника
	void aphorism::InData(ifstream &ifst) {
		ifst.getline(this->author, 50);
	}
	// Вывод параметров прямоугольника
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