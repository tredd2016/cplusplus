/**
	* Author:	Tyler Redd
	* Email:	tredd2012@gmail.com
	* Created:	09/30/2015

	*Purpose:
		This program implements a simple Caesar Cipher system for encrypting and
		decrypting plain text. 
		
		More info: https://en.wikipedia.org/wiki/Caesar_cipher
		
		// -------------------LEGAL-------------------------------------------------------------------------------------------------------------------

		Copyright (c) 2015, Tyler Redd

		Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby 
		granted, provided that the above copyright notice and this permission notice appear in all copies.

		THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED 
		WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL 
		DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS 
		ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE

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
		// [space] - 'a' = -65 -- we don't want to encrypt spaces 
		if(position_vec[i] != -65){ 
			position_vec[i] = ((position_vec[i] + key) % 26); // preform the shift
		}
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
		// [space] - 'a' = -65 -- we don't want to encrypt spaces 
		if(position_vec[i] != -65){
			position_vec[i] = ((position_vec[i] - key) % 26); // reverse the shift
			// Wrap arround -- avoid negative values
			if(position_vec[i] < 0){
				position_vec[i] = 26 + position_vec[i];
			}
		}
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
		cin.clear();
		cin.ignore(10000, '\n');

		switch (choice)
		{
		case 1:
			{
				cout << "Enter the string to encrypt: " << endl; 
				getline(cin, input_str);
				cout << "Enter the encryption key: " << endl; 
				cin >> key; 
				cin.clear();
				cin.ignore(10000, '\n');

				string encrypted = encrypt(input_str, key);
				cout << "The encrypted message is: " << endl; 
				cout << encrypted << endl << endl;

				break;
			}
		case 2:
			{
				cout << "Enter the string to decrypt: " << endl; 
				getline(cin, input_str);
				cout << "Enter the encryption key: " << endl; 
				cin >> key; 
				cin.clear();
				cin.ignore(10000, '\n');

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
