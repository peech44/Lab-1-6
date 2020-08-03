// Lab 1-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n";

	//define f1 ,f2 and more
	fraction f1(3, 5);
	fraction f2(0, 0);
	fraction f3;
	fraction f4;
	fraction f5;
	fraction f6;

	f1.show(1);
	f2.show(2);



	if (f1 == f2) {
		cout << "SAME" << endl;
	}
	if (f1 != f2) {
		cout << "Differrent" << endl;
	}
	if (f1 > f2) {
		cout << "f1 over than f2" << endl;
	}
	if (f1 < f2) {
		cout << "f1 less than f2" << endl;
	}
	if (f1 >= f2) {
		cout << "f1 over equal f2" << endl;
	}
	if (f1 <= f2) {
		cout << "f1 less equal f2" << endl;
	}
	f3 = f1 + f2;

	f3.show(3);

	f4 = f1 - f2;

	f4.show(4);

	f5 = f1 * f2;

	f5.show(5);

	f6 = f1 / f2;
	f6.show(6);

	f1.show(1);
	--f1;
	f1.show(1);

	++f1;
	f1.show(1);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
