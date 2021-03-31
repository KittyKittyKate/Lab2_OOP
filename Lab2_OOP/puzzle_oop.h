#ifndef __puzzle__
#define __puzzle__
#include "wisdom_oop.h"

namespace collection_of_wisdom_oop {
	class puzzle : public wisdom {
		char answer[20];
	public:
		string InData(ifstream &ifst);
		void Out(ofstream &ofst);
		puzzle() {}
		void MultiMethod(wisdom *other, ofstream &ofst);
		void MMAphorism(ofstream &ofst);
		void MMProverb(ofstream &ofst);
		void MMPuzzle(ofstream &ofst);
		void MMOut(ofstream &ofst);
	};
}
#endif

