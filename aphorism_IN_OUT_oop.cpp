#include <iostream>
#include "aphorism_oop.h"

using namespace std;
namespace collection_of_wisdom_oop {
	// ���� ���������� ��������������
	void aphorism::InData(ifstream &ifst) {
		ifst.getline(this->aphor, 50);
		ifst.getline(this->author, 50);
	}
	// ����� ���������� ��������������
	void aphorism::Out(ofstream &ofst) {
		ofst << "'" << this->aphor << "' - " << this->author << endl;
	}
} // end collection_of_wisdom_oop namespace