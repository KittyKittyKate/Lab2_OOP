#include <iostream>
#include "aphorism_oop.h"

using namespace std;
namespace collection_of_wisdom_oop {
	// Ввод параметров прямоугольника
	void aphorism::InData(ifstream &ifst) {
		ifst.getline(this->aphor, 50);
		ifst.getline(this->author, 50);
	}
	// Вывод параметров прямоугольника
	void aphorism::Out(ofstream &ofst) {
		ofst << "'" << this->aphor << "' - " << this->author << endl;
	}
	int aphorism::Count_Comma() {
		int comma = 0;
		int i = 0;
		while (this->aphor[i] != '\0')
		{
			if (this->aphor[i] == ',') {
				comma++;
			}
			i++;
		}
		return comma;
	}
} // end collection_of_wisdom_oop namespace