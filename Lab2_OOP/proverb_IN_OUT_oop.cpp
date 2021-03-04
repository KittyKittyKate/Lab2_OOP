#include <iostream>
#include "proverb_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {
	
	void proverb::InData(ifstream &ifst) {
		ifst.getline(this->country, 50);
	}
	
	void proverb::Out(ofstream &ofst) {
		ofst << this->country;
	}
} // end collection_of_wisdom_oop namespace