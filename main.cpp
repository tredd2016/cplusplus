/**
	* Author:	Tyler Redd
	* Email:	tredd2012@gmail.com
	* Created:	10/06/2015

	*Purpose:
		This program implements a simple Caesar Cipher system for encrypting and
		decrypting plain text. 
		
		More info: https://en.wikipedia.org/wiki/Caesar_cipher
*/ 

/*
Bugs: Decryting as a whole and spaces

*/


#include<iostream>
#include<string> 
#include<vector>
#include<cctype> //tolower()

using namespace std; 

// converts lower case string to respective int value {a,b,c..z} -> {0,1,2...25}
vector<int> char_position(string in){
	vector<int> position_vec;

	for(int i=0; i<in.size(); ++i){
		int pos = tolower(in.at(i)) - 'a'; // convert all to lower case for now
		position_vec.push_back(pos);
	}

	return position_vec;
}

string encrypt(string plain_text, int key){
	vector<int> position_vec = char_position(plain_text); // represent string as numbers
	
	for(int i=0; i<position_vec.size(); ++i){
		position_vec[i] = ((position_vec[i] + key) % 26); // preform the shift
	}

	// re-assemble string
	string rtn = "";
	for(int i=0; i<position_vec.size(); ++i){
		position_vec[i] += 'a'; // shift back to ASCII values
		rtn += (char)position_vec[i]; // Cast int as a char
	}
	return rtn; 
}

string decrypt(string encrypted, int key){
	vector<int> position_vec = char_position(encrypted); // represent string as numbers

	for(int i=0; i<position_vec.size(); ++i){
		position_vec[i] = ((position_vec[i] - key) % 26); // reverse the shift
	} 

	// re-assemble string
	string rtn = "";
	for(int i=0; i<position_vec.size(); ++i){
		position_vec[i] += 'a'; // shift back to ASCII values
		rtn += (char)position_vec[i]; // Cast int as a char
	}
	return rtn; 
}


int main(){
	while(1){
		string input_str = "";
		string output_str = "";
		int key = 0;
		int choice = 0;
	
		cout << "Welcome to the Caesar Cipher" << endl; 
		cout << "Would you like to encrypt or decrypt a message?" << endl;
		cout << "1. Encrypt" << endl << "2. Decrpyt" << endl << "3. Exit" << endl; 
		cout << "Choice: ";
		cin >> choice; 

		switch (choice)
		{
		case 1:
			{
				cout << "Enter the string to encrypt: " << endl; 
				cin >> input_str;
				cout << "Enter the encryption key: " << endl; 
				cin >> key; 
				string encrypted = encrypt(input_str, key);
				cout << "The encrypted message is: " << endl; 
				cout << encrypted << endl << endl;

				break;
			}
		case 2:
			{
				cout << "Enter the string to decrypt: " << endl; 
				cin >> input_str;
				cout << "Enter the encryption key: " << endl; 
				cin >> key; 

				string decrypted = decrypt(input_str, key);
				cout << "The decrypted message is: " << endl;
				cout << decrypted << endl << endl;
			
				break;
			}
		case 3: 
			{
				return 0;
			}
	
		default:
			{
				cout << "Invalid option, please try again" << endl << endl;
				break;
			}
		}
	}

	return 0; 
}
