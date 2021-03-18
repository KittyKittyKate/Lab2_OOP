#ifndef __wisdom__
#define __wisdom__
#include <fstream>
#include <string>
using namespace std;
namespace collection_of_wisdom_oop {
	// �����, ����������� ��� ��������� ��������.
	// �������� �����������, �����������, ��� �����,
	// �������� ����������
	class wisdom {
	public:
		char expression[100];
		int rate;
		// �������������, ���������� � ���� ������ �� ����-��
		static wisdom* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0; // ����
		virtual void Out(ofstream &ofst) = 0; // �����
		virtual void OutAphorism(ofstream &ofst, wisdom *sp);
		int Count_Comma();
		bool Compare(wisdom &other);
	
	};
} // end collection_of_wisdom_oop namespace
#endif