#include "container_oop.h"
#include "list_for_sort_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {
	// Ввод содержимого контейнера
	void container::In(ifstream &ifst, list &list) {
		while (!ifst.eof()) {
			if ((cont[length] = wisdom::In(ifst)) != 0) {
				list.Add(cont[length]);
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
			ofst << "Count of comma: " << cont[i]->Count_Comma() << endl;
		}
	}
	/*void container::Sort() { 
		for (int i = 0; i < length - 1; i++) {
			for (int j = i + 1; j < length; j++) {
				if (cont[i]->Compare(*cont[j])) { 
					wisdom *tmp = cont[i]; 
					cont[i] = cont[j]; 
					cont[j] = tmp; 
				} 
			} 
		} 
	}*/
	
	
} // end collection_of_wisdom_oop namespace