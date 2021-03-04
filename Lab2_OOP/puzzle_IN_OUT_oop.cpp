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
	int puzzle::Count_Comma() {
		int comma = 0;
		int i = 0;
		while (this->puzzle_str[i] != '\0')
		{
			if (this->puzzle_str[i] == ',') {
				comma++;
			}
			i++;
		}
		return comma;
	}
} // end collection_of_wisdom_oop namespace