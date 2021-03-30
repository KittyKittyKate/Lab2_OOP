#ifndef __aphorism__
#define __aphorism__
#include "wisdom_oop.h"

namespace collection_of_wisdom_oop {
	class aphorism : public wisdom {
		char author[50];
	public:
		string InData(ifstream &ifst);
		void Out(ofstream &ofst);
		void OutAphorism(ofstream &ofst, wisdom *sp);
		aphorism() {}
	};
} 
#endif
