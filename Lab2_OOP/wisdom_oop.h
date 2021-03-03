#ifndef __wisdom__
#define __wisdom__
#include <fstream>
using namespace std;
namespace collection_of_wisdom_oop {
	//  ласс, обобщающает всю имеющююс€ мудрость.
	// явл€етс€ абстрактным, обеспечива€, тем самым,
	// проверку интерфейса
	class wisdom {
		friend class list;
		wisdom *m_Next;
		wisdom *m_Prev;
	public:
		// иденитфикаци€, порождение и ввод фигуры из пото-ка
		static wisdom* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0; // ввод
		virtual void Out(ofstream &ofst) = 0; // вывод
		virtual int Count_Comma() = 0;
		bool Compare(wisdom &other);
		
		
		wisdom* GetNext();
	
	};
} // end collection_of_wisdom_oop namespace
#endif