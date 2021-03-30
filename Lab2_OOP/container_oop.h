#ifndef __container__
#define __container__
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {// ���������� ��������� �� ������ ����������� �������
	class container {
		enum { max_len = 100 }; // ������������ �����
		int length; // ������� �����
		wisdom *cont[max_len];
	public:
		void In(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����
		void Clear(); // ������� ���������� �� ��������
		void Sort();
		container(); // ������������� ����������
		void OutAphorisms(ofstream &ofst);
		~container() { Clear(); } // ���������� ����������
		void MultiMethod(ofstream &ofst);
	};
} // end collection_of_wisdom_oop namespace
#endif
