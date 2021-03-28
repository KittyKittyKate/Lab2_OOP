#include <iostream>
#include "puzzle_oop.h"
#include <string>

using namespace std;
namespace collection_of_wisdom_oop {

	string puzzle::InData(ifstream &ifst) {
		string Full_Line;
		string Data;
		bool Exit_Flag = true;

		do {
			getline(ifst, Full_Line);//������ � ������
			Data = FindData("Answer:", Full_Line);//� Data ����� �����
			Exit_Flag = true;

			if (Data.compare("error") == 0) { //���� ������ ���, �� ����������� ������. ������ � ��������� � ����� ��������
				string Junk; //��� ������
				getline(ifst, Junk); //����� - ������
				Junk.clear();
				return "error";
			}
			else if (Data.compare("empty") == 0) {//���� ������ ������
				Exit_Flag = false; // ���� false, �� ���������� ����
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return "";
		}
		else { //���� �� ����� �����, �� ��������� �� ������������
			this->CheckForOverflow(Data, this->answer, ifst, 20);
			Data.clear();
			Full_Line.clear();
			return "";
		}
	}
	
	void puzzle::Out(ofstream &ofst) {
		ofst << "Answer: " << this->answer;
	}
} // end collection_of_wisdom_oop namespace