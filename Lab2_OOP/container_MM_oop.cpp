#include "container_oop.h"

namespace collection_of_wisdom_oop {
	void container::MultiMethod(ofstream &ofst) {
		ofst << "Multimethod." << endl;
		for (int i = 0; i < length - 1; i++) {
			for (int j = i + 1; j < length; j++) {
				cont[i]->MultiMethod(cont[j], ofst);
				cont[i]->Out(ofst);
				cont[j]->Out(ofst);
			}
		}
	}
}