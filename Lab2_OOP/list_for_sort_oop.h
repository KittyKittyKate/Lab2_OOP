#ifndef __list__
#define __list__
#include "wisdom_oop.h"
namespace collection_of_wisdom_oop {
	class list {
	private:
		wisdom *m_First;
		wisdom *m_Last;
	public:
		void Add(wisdom* sp);
		list();
		~list();
		void Clear();
		wisdom* GetFirst();
		wisdom* GetLast();
		int GetCount();
		void Delete(wisdom* sp);
		void Clear();
		void Sort();
	};
}
#endif
