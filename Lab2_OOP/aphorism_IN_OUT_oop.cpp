#include <iostream>
#include "aphorism_oop.h"

using namespace std;
namespace collection_of_wisdom_oop {
	// ���� ���������� ��������������
	void aphorism::InData(ifstream &ifst) {
		ifst.getline(this->aphor, 50);
		ifst.getline(this->author, 50);
		ifst >> this->rate;
	}
	// ����� ���������� ��������������
	void aphorism::Out(ofstream &ofst) {
		ofst << "'" << this->aphor << "' - " << this->author << ". My rate: " << this->rate << endl;
	}
} // end collection_of_wisdom_oop namespace