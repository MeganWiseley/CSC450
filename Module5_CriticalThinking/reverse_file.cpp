/*
 * reverse_file.cpp
 *
 *  Created on: Sep 14, 2024
 *      Author: Megan - School
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> //Used for std::reverse

//Function to append user input to file
void appendToFile(const std::string& filename) {
	std::ofstream outfile;
	outfile.open(filename, std::ios::app); //Open in append mode

	if (!outfile) {
		std::cerr <<"Error Opening File for Writing" << std::endl;
		return;
	}

	std::string userInput;
	std::cout <<"Enter Text to Append to the File: ";
	std::getline(std::cin, userInput); //Get user input

	outfile << userInput << std::endl; //appending the input
	outfile.close(); //close file
	std::cout <<"Data Append to " <<filename << std::endl;
}

//Function to reverse the contents
void reverseFileContents(const std::string& inputFile, const std::string& outputFile) {
	std::ifstream infile(inputFile);
	std::ofstream outfile(outputFile);

	if (!infile) {
		std::cerr <<"Error Opening Input File (Reading)" << std::endl;
		return;
	}

	if (!outfile) {
		std::cerr <<"Error Opening Output File (Writing)" << std::endl;
		return;
	}

	//Read file content (string)
	std::string fileContent((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close(); //Close input

	//Reverse contents
	std::reverse(fileContent.begin(), fileContent.end());

	//Write reversed contents to output file
	outfile << fileContent;
	outfile.close(); //Close output

	std::cout <<"Reversed Data Stored " << outputFile << std::endl;
}

int main() {
	std::string inputFile = "CSC450_CT5_mod5.txt";
	std::string outputFile = "CSC450-mod5-reverse.txt";

	//Append data to original file
	appendToFile(inputFile);

	//Reverse the contents and store in new file
	reverseFileContents(inputFile, outputFile);

	return 0;
}


