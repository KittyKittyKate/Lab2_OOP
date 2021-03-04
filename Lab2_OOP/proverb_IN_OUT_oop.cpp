#include <iostream>
#include "proverb_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {
	// Ввод параметров треугольника
	void proverb::InData(ifstream &ifst) {
		//ifst.getline(this->prov, 50);
		ifst.getline(this->country, 50);
	}
	// Вывод параметров треугольника
	void proverb::Out(ofstream &ofst) {
		ofst << this->country;
	}
	int proverb::Count_Comma() {
		int comma = 0;
		int i = 0;
		while (this->prov[i] != '\0')
		{
			if (this->prov[i] == ',') {
				comma++;
			}
			i++;
		}
		return comma;
	}
} // end collection_of_wisdom_oop namespace