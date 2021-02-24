#include "container_oop.h"
namespace collection_of_wisdom_oop {
	// Инициализация контейнера
	container::container() : length(0) { }
	// Очистка контейнера от элементов
	void container::Clear() {
		for (int i = 0; i < length; i++) {
			delete cont[i];
		}
		length = 0;
	}
} // end collection_of_wisdom_oop namespace