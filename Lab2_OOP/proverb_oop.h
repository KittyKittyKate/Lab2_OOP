#ifndef __proverb__
#define __proverb__
#include "wisdom_oop.h"

namespace collection_of_wisdom_oop {
	class proverb : public wisdom {
		char country[50];
	public:
		string InData(ifstream &ifst);
		void Out(ofstream &ofst);
		proverb() {}
	};
}
#endif
