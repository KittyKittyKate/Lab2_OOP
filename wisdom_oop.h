#ifndef __wisdom__
#define __wisdom__
#include <fstream>
using namespace std;
namespace collection_of_wisdom_oop {
	// �����, ����������� ��� ��������� ��������.
	// �������� �����������, �����������, ��� �����,
	// �������� ����������
	class wisdom {
	public:
		// �������������, ���������� � ���� ������ �� ����-��
		static wisdom* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0; // ����
		virtual void Out(ofstream &ofst) = 0; // �����
	};
} // end collection_of_wisdom_oop namespace
#endif