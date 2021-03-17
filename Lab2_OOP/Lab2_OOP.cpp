#include <iostream>
#include <fstream>
#include "container_oop.h"
using namespace std;
using namespace collection_of_wisdom_oop;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	if (argc != 3) {
		cout << "Incorrect command line!"
			"Syntax: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Let's begin" << endl;
	container c = container();
	c.In(ifst);
	ofst << "Filled container." << endl;

	c.Out(ofst);// обыкновенный вывод
	ofst << "\n\nSorted container." << endl;
	c.Sort();//отсортировали
	c.Out(ofst);//вывод сортированного контейнера
	ofst << "\n\nFiltered container." << endl;
	c.OutAphorisms(ofst);//вывод только афоризмов

	c.Clear();
	ofst << "Empty container." << endl;
	cout << "Goodbye" << endl;
	return 0;
}
