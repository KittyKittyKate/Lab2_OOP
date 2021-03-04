#include "wisdom_oop.h"
// Необходима подключить информацию обо всех имеющихся
// геометрических фигурах
#include "aphorism_oop.h"
#include "proverb_oop.h"
using namespace std;
namespace collection_of_wisdom_oop {
	// Ввод параметров обобщенной фигуры
	wisdom* wisdom::In(ifstream &ifst) {
		wisdom *sp;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new aphorism;
			break;
		case 2:
			sp = new proverb;
			break;
		default:
			return 0;
		}
		ifst.getline(sp->expression, 50);
		sp->InData(ifst);
		ifst >> sp->rate;
		return sp;
	}
} // end collection_of_wisdom_oop namespace