#ifndef __wisdom__
#define __wisdom__
#include <fstream>
#include <string>

using namespace std;

namespace collection_of_wisdom_oop {
	class wisdom {
	public:
		char expression[100];
		int rate;
		static wisdom *In(ifstream &ifst);
		virtual string InData(ifstream &ifst) = 0;
		virtual void Out(ofstream &ofst) = 0;
		virtual void OutAphorism(ofstream &ofst, wisdom *sp);
		int Count_Comma();
		bool Compare(wisdom &other);
		static string FindData(const string &Text, string &Line);
		static void Junk(ifstream &ifst);
		static char &CheckForOverflow(string &Data, char char_text[], ifstream &ifst, int Len);
	};
}
#endif
