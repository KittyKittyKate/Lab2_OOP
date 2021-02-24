#ifndef __proverb__
#define __proverb__
// Требуется описание класса shape
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	// треугольник
	class proverb : public wisdom {
		char prov[50];
		char country[50];
	public:
		// переопределяем интерфейс класса
		void InData(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод
		proverb() {} // создание без инициализации.
	};
} // end collection_of_wisdom_oop namespace
#endif
