#ifndef __puzzle__
#define __puzzle__

#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	
	class puzzle : public wisdom {
		//char puzzle_str[200];
		char answer[20];
	public:
		// переопределяем интерфейс класса
		string InData(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод
		puzzle() {} // создание без инициализации.
	};
} // end collection_of_wisdom_oop namespace
#endif

