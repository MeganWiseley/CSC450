/*
 * main.cpp
 *
 *  Created on: Aug 24, 2024
 *      Author: Megan - School
 */

#include <iostream>
#include <string>

int main() {
	std::string firstString;
	std::string secondString;
	std::string concatenatedString;

	//Loop to take inputs from user 3x
	for (int i = 0; i < 3; ++i) {
		std::cout <<"Enter the first string (attempt " << i+1 << "): ";
		std::getline(std::cin, firstString);

		std::cout <<"Enter the second string (attempt " << i+1 << "): ";
		std::getline(std::cin, secondString);

		//Concatenating the two strings with a space between the strings
		concatenatedString = firstString + " " + secondString;

		//Output results
		std::cout <<"Concatenated String: " << concatenatedString << std::endl;
		std::cout << std::endl; //Blank line between results
	}

	return 0;
}


