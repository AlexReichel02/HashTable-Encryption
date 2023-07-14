/***************************************************************
  Student Name: Alex Reichel
  File Name: main.cpp
  Assignment number Project 01

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Hash.hpp"
#include "FileMaker.hpp"
using namespace std;


	int main() {


		FileMaker obj = FileMaker();
		obj.readFile("names.txt");
		obj.writeRawFile("rawdata.txt");
		obj.writeEncryptFile("encrypteddata.txt");


		 Hash h;
		 obj.fillHash(h);
		 obj.tester(h);



	return 0;
}

