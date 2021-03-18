#include "wisdom_oop.h"
// ���������� ���������� ���������� ��� ���� ���������
// �������������� �������
#include "aphorism_oop.h"
#include "proverb_oop.h"
#include "puzzle_oop.h"
#include <iostream>
#include <string>
using namespace std;
namespace collection_of_wisdom_oop {
	// ���� ���������� ���������� ������
	wisdom* wisdom::In(ifstream &ifst) {
		wisdom *sp;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new aphorism;
			break;
		case 2:
			sp = new proverb;
			break;
		case 3:
			sp = new puzzle;
			break;
		default: //���� �������� ����, �� ���������. ��������� �������: ����� �������� � ������������ ������ ������ �� ����� ���������� � ���������
			char Junk[100]; //��� ������
			ifst.getline(Junk, 100); //����� - ���������
			ifst.getline(Junk, 100); //����� - ���������� ��������������
			ifst.getline(Junk, 100); //����� - ������
			return 0;
		}
		string Line; //��������� ������� �� ������ ������������
		getline(ifst, Line); //������ ��������� � Line
		if (Line.length() < 100) { //�������� �� ������������ - ���� ����� Line < 100
			strcpy_s(sp->expression, 100, Line.c_str());
			sp->InData(ifst);
			ifst >> sp->rate;
			return sp;
		}
		else { //����� �������� ������ ������
			Line.resize(99);
			strcpy_s(sp->expression, 100, Line.c_str());
			sp->InData(ifst);
			ifst >> sp->rate;
			return sp;
		}
		Line.clear();
	}
	bool wisdom::Compare(wisdom &other) {
		return Count_Comma() > other.Count_Comma(); 
	}
	int wisdom::Count_Comma() {
		int comma = 0;
		int i = 0;
		while (this->expression[i] != '\0')
		{
			if (this->expression[i] == ',') {
				comma++;
			}
			i++;
		}
		return comma;
	}
	void wisdom::OutAphorism(ofstream &ofst, wisdom *sp) {
		ofst << endl; 
	}
} // end collection_of_wisdom_oop namespace