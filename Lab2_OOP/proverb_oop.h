#ifndef __proverb__
#define __proverb__
// ��������� �������� ������ shape
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	// �����������
	class proverb : public wisdom {
		char prov[50];
		char country[50];
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����
		proverb() {} // �������� ��� �������������.
	};
} // end collection_of_wisdom_oop namespace
#endif
