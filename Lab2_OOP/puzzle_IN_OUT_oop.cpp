#include <iostream>
#include "puzzle_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {

	void puzzle::InData(ifstream &ifst) {
		ifst.getline(this->answer, 20);
	}
	
	void puzzle::Out(ofstream &ofst) {
		ofst << "Answer: " << this->answer;
	}
} // end collection_of_wisdom_oop namespace