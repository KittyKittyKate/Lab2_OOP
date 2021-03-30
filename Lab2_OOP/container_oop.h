#ifndef __container__
#define __container__
#include "wisdom_oop.h"

namespace collection_of_wisdom_oop {
	class container {
		enum { max_len = 100 };
		wisdom *cont[max_len];
	public:
		int length;
		void In(ifstream &ifst); 
		void Out(ofstream &ofst);
		void Clear();
		void Sort();
		container();
		void OutAphorisms(ofstream &ofst);
		~container() { Clear(); }
	};
} 
#endif
