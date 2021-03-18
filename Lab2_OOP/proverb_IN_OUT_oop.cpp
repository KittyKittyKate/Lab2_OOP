#include <iostream>
#include "proverb_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {
	
	void proverb::InData(ifstream &ifst) {
		string Line; //��������� ������� �� ������ ������������
		getline(ifst, Line); //������ ��������� � Line
		if (Line.length() < 50) { //�������� �� ������������ - ���� ����� Line < 50
			strcpy_s(this->country, 50, Line.c_str());
		}
		else {
			Line.resize(49);
			strcpy_s(this->country, 50, Line.c_str());
		}
		Line.clear();
	}
	
	void proverb::Out(ofstream &ofst) {
		ofst << this->country;
	}
} // end collection_of_wisdom_oop namespace