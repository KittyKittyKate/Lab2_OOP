#include "wisdom_oop.h"
#include "aphorism_oop.h"
#include "proverb_oop.h"
#include "puzzle_oop.h"
#include <iostream>
#include <string>
#include "limits.h"

using namespace std;

namespace collection_of_wisdom_oop {
	wisdom* wisdom::In(ifstream &ifst) {
		wisdom *sp;
		int k = 0;
		string Full_Line;
		getline(ifst, Full_Line);	//��������� ������ � Full_Line.
		string Data = FindData("Type of wisdom:", Full_Line);

		if (Data.compare("error") != 0 && Data.compare("empty") != 0) {	//���� FindData �� ������� "error" ��� "empty".
			try {
				if (isdigit(Data[0]) == 0) {
					throw Data;	//����������: Data - ������, � �� �����
				}

				if (static_cast<int>(stoi(Data, 0, 10)) > INT_MAX) {	//���� Data > ����. ��������, ������� ����� ����� int.
					cout << "ERROR: overflow (Type of wisdom > INT_MAX)." << endl;
				}
				else if (static_cast<int>(stoi(Data, 0, 10)) < INT_MIN) {	//���� Data < ���. ��������, ������� ����� ����� int.
					cout << "ERROR: overflow (Type of wisdom < INT_MIN)." << endl;
				}
				else {	//���� INT_MIN < Data < INT_MAX.
					k = static_cast<int>(stoi(Data, 0, 10));
				}
			}
			catch (string Data) {	//�������� �� ������.
				cout << "ERROR: 'Type of wisdom' should be int ('Type of wisdom' == " << Data << ")." << endl;
				k = 0;
			}
		}
		else if (Data.compare("empty") == 0) {	//���� FindData ������� "empty", �� ����� �� �������.
			return 0;
		}

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
		default:	//���, ����� 1, 2, 3, �������� ���� (������������ ��� ��������). ���������� ��� ������. ����� �� �������.
			Junk(ifst);
			return 0;
		}
		bool Exit_Flag = true;
		//����� ��������� ���� "Expression:".
		do {
			getline(ifst, Full_Line);	//������ ��������� � Full_Line.
			Data = FindData("Expression:", Full_Line);
			Exit_Flag = true;

			if (Data.compare("error") == 0) {	//���� FindData ������� "error" (�� ����� ��������� "Expression:"), �� ���������� ����������� ������.
				delete[] sp;
				string Junk; //��� ������.
				getline(ifst, Junk); //����� - ���������� ��������������.
				getline(ifst, Junk); //����� - ������.
				Junk.clear();
				return 0;
			}
			else if (Data.compare("empty") == 0) {//���� FindData ������� "empty".
				Exit_Flag = false; 
			}

		} while ((ifst.eof() == false) && (Exit_Flag == false)); //���� �� ����� ����� � Exit_Flag == false - ���� ����� ������������.

		if (ifst.eof()) {//�������� � ����� �����.
			cout << "INFORMATION: the end of file." << endl;
			return 0;
		}
		else { //���� ����� ����� ��� �� ��������.
			*sp->expression = CheckForOverflow(Data, sp->expression, ifst, 100);//����� ���������� �������� �� ������������ � ��������� ��������� � expression.
		}

		if (sp->InData(ifst) == "error") {// ���� InData ���������� "error", �� �������� �� ��������� � ���������, ���������� ����� �� �������.
			delete[] sp;
			return 0;
		}

		if (ifst.eof()) {//������ ����� �� InData ����� ��������� � �� ������� ����� �����.
			return 0;
		}
		//����� ��������� ���� "Rate:".
		do {
			getline(ifst, Full_Line);
			Data = FindData("Rate:", Full_Line);//������ ��������� � Full_Line.

			if (Data.compare("error") != 0 && Data.compare("empty") != 0) {//���� FindData �� ������� "error" ��� "empty".
				try {
					if (isdigit(Data[0]) == 0) {
						throw Data; //����������: Data - ������, � �� �����.
					}

					if (static_cast<int>(stoi(Data, 0, 10)) > 10) {//���� Data > 10.
						delete[] sp;
						cout << "ERROR: unexpected value (Rate > 10)." << endl;
						return 0;
					}
					else if (static_cast<int>(stoi(Data, 0, 10)) < 0) {//���� Data < 0.
						delete[] sp;
						cout << "ERROR: unexpected value (Rate < 0)." << endl;
						return 0;
					}
					else {//���� 0 < Data < 10.
						sp->rate = static_cast<int>(stoi(Data, 0, 10));
						return sp;//��� ������ �������� ������ ��������, ����� ����� ������� ��������.
					}
				}
				catch (string Data) {//��������, ��� ���� "Rate:" - ������ ��������� �����.
					cout << "ERROR: 'Rate' should be int ('Rate' == " << Data << ")." << endl;
					delete[] sp;
					return 0;
				}

			}
			else if (Data.compare("empty") == 0) { //���� FindData ������� "empty".
				Exit_Flag = false;
			}
			else if (Data.compare("error") == 0) { //���� FindData ������� "error".
				cout << "ERROR: misprint in field 'Rate:'." << endl;
				delete[] sp;
				return 0;
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));//���� �� ����� ����� � Exit_Flag == false - ���� ����� ������������.

		if (ifst.eof()) {//�������� � ����� �����.
			cout << "INFORMATION: the end of file." << endl;
			return 0;
		}

		Full_Line.clear();//������ Full_Line.
	}
	string wisdom::FindData(const string &Text, string &Line) {
		string Data;

		if (Line.compare("") == 0) {//���� � ������ ������ ���.
			cout << "Empty line." << endl;
			return "empty";
		}
		try {//����� ���� ���������.
			int Position = static_cast<int>(Line.find(Text));

			if (Position != 0) {
				throw Position;
			}

			try {//����  Position == 0 (������ �� ��������).
				int Difference = static_cast<int>(Line.length()) - static_cast<int>(Text.length());

				if (Difference == 0) {
					throw Text;
				}

				Data = Line.substr(static_cast<int>(Text.length()), Difference);
				return Data;
			}
			catch (string s) {//���� � ���� ����������� ������.
				cout << "ERROR: the data is empty (" << s << ")." << endl;
				return "error";
			}
		}
		catch (int Position) {
			if (Position != -1) {//� ������, ���� ���� ��������, ������ ��� ����� �����������.
				cout << "WARNING: unexpected format of data (" << Line.substr(0, Position + static_cast<int>(Text.length())) << ")." << endl;
				Data = Line.substr(Position + static_cast<int>(Text.length()), static_cast<int>(Line.length()) - 1);
				return Data;
			}
			else if (Position == -1) {//� ������, ���� ������ ������� �����������.
				cout << "ERROR: incorrect data format." << endl;
				return "error";
			}
		}
	}
	void wisdom::Junk(ifstream &ifst) {
		string Junk; //��� ������.
		getline(ifst, Junk); //����� - ���������.
		getline(ifst, Junk); //����� - ���������� ��������������.
		getline(ifst, Junk); //����� - ������.
		Junk.clear();
	}
	char& wisdom::CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len) {
		if (static_cast<int>(Data.length()) < Len) { //�������� �� ������������: ���� ����� ������ < Len, �� ������ ������� ��������� � ����������.
			strcpy_s(char_text, Len, Data.c_str());
			return *char_text;
		}
		else { //���� ����� ������ > Len, �� �������� ������ ������ � ��������� ����������.
			Data.resize(Len - 1);
			strcpy_s(char_text, Len, Data.c_str());
			return *char_text;
		}
	}
	bool wisdom::Compare(wisdom &other) {
		return Count_Comma() > other.Count_Comma(); 
	}
	int wisdom::Count_Comma() {
		int comma = 0;
		int i = 0;

		while (this->expression[i] != '\0') {
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
}