/***************************************************************
  Student Name: Alex Reichel
  File Name: FileMaker.h
  Assignment number Project 01

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/


#ifndef FILEMAKER_HPP_
#define FILEMAKER_HPP_
#include<iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include "Hash.hpp"
using namespace std;

class FileMaker {

public:
	FileMaker();
	void tester(Hash obj);
	void readFile(string fileName);
	void writeRawFile(string fileName);
	void writeEncryptFile(string fileName);
	string encryption(string userID);
	void fillHash(Hash obj);
	vector<string> userNames;
	vector<string> oldPassWords;
	vector<string> newPassWords;
	virtual ~FileMaker();

};

#endif /* FILEMAKER_H_ */
