#ifndef __puzzle__
#define __puzzle__

#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	
	class puzzle : public wisdom {
		char puzzle_str[200];
		char answer[20];
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����
		int Count_Comma();
		puzzle() {} // �������� ��� �������������.
	};
} // end collection_of_wisdom_oop namespace
#endif

