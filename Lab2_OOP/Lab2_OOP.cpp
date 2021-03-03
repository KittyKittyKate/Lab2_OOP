#include <iostream>
#include <fstream>
#include "container_oop.h"
#include "list_for_sort_oop.h"
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
	list MyList = list();

	c.In(ifst, MyList);//заполняем не только контейнер, но и список
	ofst << "Filled container." << endl;

	MyList.Sort();
	//c.Sort();

	c.Out(ofst);
	c.Clear();
	ofst << "Empty container." << endl;
	cout << "Goodbye" << endl;
	return 0;
}
int PrintCaseMenu(){
	printf("Sort:\n");
	printf("1. By Name\n");
	printf("2. By Year\n");
	printf("3. By Count of Faculets\n");
	printf("4. By Count of Students\n");
	printf("5. By Ubiley\n");
	printf("6. Show the result\n");
	printf("You chose: ");
	int k;
	cin >> k;
	return k;
}

