#ifndef __aphorism__
#define __aphorism__
// ��������� �������� ������ wisdom
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	// �������������
	class aphorism : public wisdom {
		char aphor[50];
		char author[50];
		int rate;
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����
		aphorism() {} // �������� ��� �������������.
	};
} // end collection_of_wisdom_oop namespace
#endif
