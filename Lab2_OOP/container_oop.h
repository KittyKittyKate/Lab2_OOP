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
		container(); // ������������� ����������
		~container() { Clear(); } // ���������� ����������
	};
} // end collection_of_wisdom_oop namespace
#endif
