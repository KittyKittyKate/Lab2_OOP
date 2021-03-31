#include "wisdom_oop.h"
#include "proverb_oop.h"

namespace collection_of_wisdom_oop {
	void proverb::MultiMethod(wisdom *other, ofstream &ofst)
	{
		other->MMProverb(ofst);
	}
}