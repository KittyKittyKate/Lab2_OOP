#ifndef __proverb__
#define __proverb__
// ��������� �������� ������ shape
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	// �����������
	class proverb : public wisdom {
		char country[50];
		
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����
		proverb() {} // �������� ��� �������������.
		//lab 7
		void MultiMethod(wisdom *other, ofstream &ofst);
		void MMAphorism(ofstream &ofst);
		void MMProverb(ofstream &ofst);
		void MMOut(ofstream &ofst);
	};
} // end collection_of_wisdom_oop namespace
#endif
