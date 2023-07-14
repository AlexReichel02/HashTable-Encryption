/***************************************************************
  Student Name: Alex Reichel
  File Name: FileMaker.cpp
  Assignment number Project 01

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/


#include "FileMaker.hpp"

FileMaker::FileMaker() {

}

/***
    Function takes in a Hash object in order to test and print certain hash values
    Function opens rawdata file and only retrieves the 1,3,5,7,9 entry of user ID' and passwords in order to test
	Function encrypts each plain password , then finds the userID in the hash table
	Function then tests whether or not the newly encrypted password matches what is already hashed
    Function writes output to the screen and notifies user if it is a match or not
    Function also test 5 entries with an added character to each password, testing whether or not these illegal password will match in the hash table
   */
void FileMaker::tester(Hash obj){

			 vector<string> testUser;
			 vector<string> testPassWord;
			 string testPass;
			 string illegalPass;
			 string newTestPass;
			 string line;

			 ifstream file2 ("rawdata.txt");
			 if (file2.is_open()){

			for (int lineno = 1; getline (file2,line) && lineno < 10; lineno++){
			 	if (lineno == 1 || lineno == 3 || lineno == 5 || lineno == 7 || lineno == 9){

			 		int n = line.length();
			 		char lineArray[n + 1];
			 	    strcpy(lineArray, line.c_str());
			 	    char *token = strtok(lineArray, " ");
			 	    int counter=0;

			 			while (token != NULL){
			 				counter++;
			 				 if(counter %2 != 0){
			 					 testUser.push_back(token);
			 				 }else{
			 				     testPassWord.push_back(token);
			 					}
			 				token = strtok(NULL, " ");
			 	        }

			 	      }
			 	}
			 }else{
			 	cout << "Can not open the file";
			 	}

			cout<<"Legal: " <<endl;
			cout << "UserID :   Password:    Result:      " <<endl;

			for(int i=0;i<testUser.size();i++){

				testPass = encryption(testPassWord[i]);
				if(obj.findPassWord(testUser[i]) == testPass){
					cout << testUser[i] + "    " + testPass + "     Match   " << endl;
				}else {
					cout << "No Match" << endl;
				}

			}

			cout<<endl;
			cout<<endl;


			cout<<"Illegal: " <<endl;
			cout << "UserID :    Password:     Result:      " <<endl;

				for(int i=0;i<testUser.size();i++){

					illegalPass = testPassWord[i] += "a";
					newTestPass = encryption(illegalPass) += "a";

					  if(obj.findPassWord(testUser[i]) == newTestPass){
							cout << testUser[i] + "    " + newTestPass + "     Match   " << endl;
							}else {
							cout << testUser[i] + "    " + newTestPass + "     No Match   " << endl;
							}
						}
			cout<<endl;
}


/***
    Function takes in a string parameter representing what the user wants to name the file
	Function randomly generates each user in the User vector a random 9 length lowercase password
    Function writes each user's ID and new password to the specified outfile
   */
void FileMaker::writeRawFile(string fileName){

	const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
	int string_length = sizeof(alphanum)-1;
	ofstream outFile(fileName);
	srand(time(0));
	for(int i=0;i<userNames.size();i++){
			string passWords ="";
			for(int i = 0; i < 9; i++){
				    passWords +=  alphanum[rand() % string_length];
				 }


				outFile << userNames[i]<< " " << passWords << endl;
			}

		outFile.close();
}


/***
    Function takes in a string parameter representing what the user wants to name the file
    Function then creates a new outfile with user specifed name
    Function the opens and reads Rawdata.txt to retrieve the user id and password
    Function then calls the encrypt() function to encrypt each password
    Function writes each  user's ID, old password , and new encrypted password to the specified outfile
*/
void FileMaker::writeEncryptFile(string fileName){

		ofstream outFile2(fileName);
		ifstream inFile2;
		string userName2;
		string passWord2;
		string encrypt="";

		inFile2.open("rawdata.txt");

		if(!inFile2){
					cout<<"unable to open"<<endl;
				}else{


					while(!inFile2.eof()){

						inFile2>>userName2>>passWord2;
						encrypt = encryption(passWord2);
						newPassWords.push_back(encrypt);
						outFile2 <<  userName2<< " " << passWord2 << " " << encrypt << endl;
							}

				}

		outFile2.close();

}


/***
    Function takes in a string parameter repressing the file name
    Function reads through the file and only stores the first column on the file
    Functions places first column of file within a vector
*/
void FileMaker::readFile(string fileName){

			ifstream inFile;
			string names;
			int order;
			double score1,score2;
			inFile.open(fileName);

		if(!inFile){
				cout<<"unable to open"<<endl;
			}else{


				while(!inFile.eof()){
					inFile>>names>>score1>>score2>>order;
					userNames.push_back(names);
						}


			}
}


/***
    Function takes in a string parameter representing string that needs to be encrypted
    Function generates and returns an encrypted password based off given user input
*/
string FileMaker::encryption(string userId){

		string p1,p2,p3,p4,p5,p6,p7,p8,p9;
		string newPass =" ";
		int n = userId.length();
		char passWords[n + 1];
		strcpy(passWords, userId.c_str());

		      	if (passWords[0] > 96 && passWords[0] < 106 ){
		      			p1 = passWords[0] + 17 ;
		      		}else if(passWords[0] > 105 && passWords[0] < 122 ){
		      			p1 = passWords[0] - 9 ;
		      	}

		    	if(passWords[1] > 96 && passWords[1] < 111 ){
		    	      	p2 = passWords[1] + 12;
		    	     }else if(passWords[1] > 110 && passWords[1] < 123 ){
		    	      	p2 = passWords[1] - 14 ;
		    	     }


		    	if (passWords[2] > 96 && passWords[2] < 110 ){
		    	      	p3 = passWords[2] + 13 ;
		    	     }else if(passWords[2] > 109 && passWords[2] < 123 ){
		    	      	p3 = passWords[2] - 13 ;
		    	      	}


		    	if (passWords[3] > 96 && passWords[3] < 101 ){
		    	      	p4 = passWords[3] + 22 ;
		    	     }else if(passWords[3] > 100 && passWords[3] < 123 ){
		    	      	p4 = passWords[3] - 4 ;
		    	      	}

		    	if (passWords[4] > 96 && passWords[4] < 115){
		    	      	p5 = passWords[4] + 8 ;
		    	     }else if(passWords[4] > 114 && passWords[4] < 123 ){
		    	      	p5 = passWords[4] - 18 ;
		    	      	}


		    	if (passWords[5] > 96 && passWords[5] < 106 ){
		    		      	p6 = passWords[5] + 17 ;
		    		 }else if(passWords[5] > 105 && passWords[5] < 122 ){
		    		      	p6 = passWords[5] - 9 ;
		    		      	}

		    	if (passWords[6] > 96 && passWords[6] < 111 ){
		    		   p7 = passWords[6] + 12;
		    		}else if(passWords[6] > 110 && passWords[6] < 123 ){
		    			p7 = passWords[6] - 14 ;
		    		    	   }


		    	if (passWords[7] > 96 && passWords[7] < 110 ){
		    		  	  p8 = passWords[7] + 13 ;
		    		}else if(passWords[7] > 109 && passWords[7] < 123 ){
		    		    	p8 = passWords[7] - 13 ;
		    		   }


		    	if (passWords[8] > 96 && passWords[8] < 101 ){
		    		  	p9 = passWords[8] + 22 ;
		    		  }else if(passWords[8] > 100 && passWords[8] < 123 ){
		    			  p9 = passWords[8] - 4 ;
		    		   }

		 newPass = p1+p2+p3+p4+p5+p6+p7+p8+p9;
		 return newPass;
}


/**
    Function fills Hash table with data from vectors storing usernames and passwords
    Function takes in Hash object
    Function calls the Insert function from the hash class
    whilst in a loop adding each individual user and password from their stored vectors
*/
	void FileMaker::fillHash(Hash obj){

		for(int i=0;i<userNames.size();i++){
			obj.insertItem(userNames[i],newPassWords[i]);
		}
	}



FileMaker::~FileMaker() {
	// TODO Auto-generated destructor stub
}

