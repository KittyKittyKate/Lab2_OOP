#include "container_oop.h"

namespace collection_of_wisdom_oop {
	container::container() : length(0) {}
	void container::Clear() {
		for (int i = 0; i < length; i++) {
			delete cont[i];
		}
		length = 0;
	}
}