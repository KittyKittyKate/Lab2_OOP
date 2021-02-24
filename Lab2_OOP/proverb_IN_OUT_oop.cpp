#include <iostream>
#include "proverb_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {
	// Ввод параметров треугольника
	void proverb::InData(ifstream &ifst) {
		ifst.getline(this->prov, 50);
		ifst.getline(this->country, 50);
		ifst >> this->rate;
	}
	// Вывод параметров треугольника
	void proverb::Out(ofstream &ofst) {
		ofst << "'" << this->prov << "' - " << this->country << ". My rate: " << this->rate << endl;
	}
} // end collection_of_wisdom_oop namespace