#ifndef __aphorism__
#define __aphorism__
// Требеутся описание класса wisdom
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	class aphorism : public wisdom {
		char author[50];
		
	public:
		// переопределяем интерфейс класса
		void InData(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод
		void OutAphorism(ofstream &ofst, wisdom *sp);
		aphorism() {} // создание без инициализации.
		//lab 7
		void MultiMethod(wisdom *other, ofstream &ofst);
		void MMAphorism(ofstream &ofst);
		void MMProverb(ofstream &ofst);
	};
} // end collection_of_wisdom_oop namespace
#endif
