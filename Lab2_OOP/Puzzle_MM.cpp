#include "wisdom_oop.h"
#include "puzzle_oop.h"

namespace collection_of_wisdom_oop {
	void puzzle::MultiMethod(wisdom *other, ofstream &ofst)
	{
		other->MMPuzzle(ofst);
	}
}