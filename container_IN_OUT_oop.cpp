#include "container_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {
	// Ввод содержимого контейнера
	void container::In(ifstream &ifst) {
		while (!ifst.eof()) {
			if ((cont[length] = wisdom::In(ifst)) != 0) {
				length++;
			}
		}
	}
	// Вывод содержимого контейнера
	void container::Out(ofstream &ofst) {
		ofst << "Container contents " << length
			<< " elements." << endl;
		for (int i = 0; i < length; i++) {
			ofst << i << ": ";
			cont[i]->Out(ofst);
		}
	}
} // end collection_of_wisdom_oop namespace