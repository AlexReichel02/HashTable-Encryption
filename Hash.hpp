/***************************************************************
  Student Name: Alex Reichel
  File Name: Hash.hpp
  Assignment number Project 01

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef HASH_HPP_
#define HASH_HPP_
#include<iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Hash {

	

	public:
		Hash();
	 	void insertItem(string userID,string passWord);
	    int hashFunction(string userID);
	    string findPassWord(string userID);


	private:
	   static const int BUCKET = 88800;

	    struct User{
	    	string userID;
	    	string passWord;
	    	User* next;
	    };

	    User* hashTable[BUCKET];

};

#endif /* HASH_H_ */
