#ifndef __aphorism__
#define __aphorism__
// ��������� �������� ������ wisdom
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	class aphorism : public wisdom {
		char author[50];
		
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����
		void OutAphorism(ofstream &ofst, wisdom *sp);
		aphorism() {} // �������� ��� �������������.
		//lab 7
		void MultiMethod(wisdom *other, ofstream &ofst);
		void MMAphorism(ofstream &ofst);
		void MMProverb(ofstream &ofst);
	};
} // end collection_of_wisdom_oop namespace
#endif
