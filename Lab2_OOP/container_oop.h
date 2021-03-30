#ifndef __container__
#define __container__
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {// Простейший контейнер на основе одномерного массива
	class container {
		enum { max_len = 100 }; // максимальная длина
		int length; // текущая длина
		wisdom *cont[max_len];
	public:
		void In(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод
		void Clear(); // очистка контейнера от мудрости
		void Sort();
		container(); // инициализация контейнера
		void OutAphorisms(ofstream &ofst);
		~container() { Clear(); } // утилизация контейнера
		void MultiMethod(ofstream &ofst);
	};
} // end collection_of_wisdom_oop namespace
#endif
