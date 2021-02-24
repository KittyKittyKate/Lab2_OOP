#ifndef __aphorism__
#define __aphorism__
// Требеутся описание класса wisdom
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	// прямоугольник
	class aphorism : public wisdom {
		char aphor[50];
		char author[50];
		int rate;
	public:
		// переопределяем интерфейс класса
		void InData(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод
		aphorism() {} // создание без инициализации.
	};
} // end collection_of_wisdom_oop namespace
#endif
