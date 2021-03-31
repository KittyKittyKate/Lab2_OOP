#include "wisdom_oop.h"
#include "aphorism_oop.h"

namespace collection_of_wisdom_oop {
	void aphorism::MultiMethod(wisdom *other, ofstream &ofst)
	{
		other->MMAphorism(ofst);
	}
}