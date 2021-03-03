#ifndef __container__
#define __container__
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {// ���������� ��������� �� ������ ����������� �������
	class container {
		enum { max_len = 100 }; // ������������ �����
		int length; // ������� �����
		wisdom *cont[max_len];
		
	public:
		void In(ifstream &ifst, list &list); // ����
		void Out(ofstream &ofst); // �����
		void Clear(); // ������� ���������� �� ��������
		void Sort(); //����������
		container(); // ������������� ����������
		~container() { Clear(); } // ���������� ����������
		
	};
} // end collection_of_wisdom_oop namespace
#endif
