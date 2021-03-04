#include <iostream>
#include "puzzle_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {

	void puzzle::InData(ifstream &ifst) {
		ifst.getline(this->puzzle_str, 200);
		ifst.getline(this->answer, 20);
	}
	// Вывод параметров треугольника
	void puzzle::Out(ofstream &ofst) {
		ofst << "'" << this->puzzle_str << "' - Answer: " << this->answer << endl;
	}
} // end collection_of_wisdom_oop namespace