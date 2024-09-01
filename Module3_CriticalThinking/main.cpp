/*
 * main.cpp
 *
 *  Created on: Sep 1, 2024
 *      Author: Megan - School
 */
#include <iostream>
using namespace std;

int main() {
	int num1, num2, num3;

	cout <<"Enter three integers: " << endl;
	cin >> num1 >> num2 >> num3;

	int* ptr1 = new int;
	int* ptr2 = new int;
	int* ptr3 = new int;

	*ptr1 = num1;
	*ptr2 = num2;
	*ptr3 = num3;

	cout << "Integers Entered: " << endl;
	cout << "Integer 1: " << num1 << " (Pointer Value: " << *ptr1 << ")" << endl;
	cout << "Integer 2: " << num2 << " (Pointer Value: " << *ptr2 << ")" << endl;
	cout << "Integer 3: " << num3 << " (Pointer Value: " << *ptr3 << ")" << endl;

	delete ptr1;
	delete ptr2;
	delete ptr3;

	ptr1 = nullptr;
	ptr2 = nullptr;
	ptr3 = nullptr;

	return 0;
}



