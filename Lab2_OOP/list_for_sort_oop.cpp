#include "list_for_sort_oop.h"

namespace collection_of_wisdom_oop {
	void list::Add(wisdom* sp) { //ok
		if (m_First == NULL)
		{
			m_First = sp;
			m_Last = sp;
		}
		else
		{
			m_Last->m_Next = sp;
			m_Last = sp;
			m_Last->m_Next = m_First;
		}
	}

	list::list(){
		m_First = NULL;
		m_Last = NULL;
	}

	list::~list(){
		Clear();
	}

	void list::Clear(){
		while (m_First != NULL)
		{
			wisdom* sp = m_First->GetNext();
			delete m_First;
			m_First = sp;
		}
		m_Last = NULL;
	}

	wisdom* list::GetFirst(){
		return m_First;
	}

	wisdom* list::GetLast(){
		return m_Last;
	}

	int list::GetCount(){
		int count = 0;
		wisdom* sp = m_First;
		while (sp != NULL)
		{
			count++;
			sp = sp->GetNext();
		}
		return count;
	}

	void list::Delete(wisdom* sp){
		if (sp->m_Prev != NULL)
		{
			sp->m_Prev->m_Next = sp->m_Next;
		}
		else
		{
			m_First = sp->m_Next;
		}
		if (sp->m_Next != NULL)
		{
			sp->m_Next->m_Prev = sp->m_Prev;
		}
		else
		{
			m_Last = sp->m_Prev;
		}
		delete sp;
	}

	void list::Clear(){
		while (m_First != NULL)
		{
			wisdom* sp = m_First->GetNext();
			delete m_First;
			m_First = sp;
		}
		m_Last = NULL;
	}

	void list::Sort() {
		int count = GetCount();

		if (count == 0)
			return;
		wisdom** newmas = new wisdom*[count];
		newmas[0] = m_First;
		for (int i = 1; i < count; i++)
			newmas[i] = newmas[i - 1]->m_Next;
		// сортировка
		if (count > 1){
			for (int i = 0; i < count - 1; i++) {
				for (int j = i + 1; j < count; j++) {
					if (newmas[i]->Compare(*newmas[j])) {
						wisdom *tmp = newmas[i];
						newmas[i] = newmas[j];
						newmas[j] = tmp;
					}
				}
			}
		}
		
	}
}