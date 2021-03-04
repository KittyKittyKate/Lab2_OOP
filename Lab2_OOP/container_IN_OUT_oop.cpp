#include "container_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {
	// ���� ����������� ����������
	void container::In(ifstream &ifst) {
		while (!ifst.eof()) {
			if ((cont[length] = wisdom::In(ifst)) != 0) {
				length++;
			}
		}
	}
	// ����� ����������� ����������
	void container::Out(ofstream &ofst) {
		ofst << "Container contents " << length
			<< " elements." << endl;
		for (int i = 0; i < length; i++) {
			ofst << i << ": ";
			ofst << "'" << cont[i]->expression << "' - ";
			cont[i]->Out(ofst);
			ofst << ". My rate: " << cont[i]->rate << endl;
		}
	}
} // end collection_of_wisdom_oop namespace