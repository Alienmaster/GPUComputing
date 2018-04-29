// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void encryptFile();
void decryptFile();

int main()
{
	bool loop_program;
	loop_program = true;
	while (loop_program)
	{
		cout << "e) entschluesseln v) verschluesseln q) beenden\n";
		char MenuInput;
		cin >> MenuInput;
		switch (MenuInput)
		{
		case 'v':
			encryptFile();
			break;
		case 'e':
			decryptFile();
			break;
		case 'q':
			return 0;
		default:
			cout << "Bitte versuchen Sie es erneut\n";
		}
	}
}

void encryptFile()
{
	string inputstring;
	string keystring;
	const char* inputc;
	const char* keyc;
	int xy;
	ifstream inputfile("Text.txt");
	ifstream keyfile("key.txt");
	getline(inputfile, inputstring);
	inputfile.close();
	getline(keyfile, keystring);
	keyfile.close();
	
	transform(inputstring.begin(), inputstring.end(), inputstring.begin(), ::toupper);
	inputc = inputstring.c_str();
	keyc = keystring.c_str();
	for (int i = 0; i <= inputstring.length() - 1; i++)
	{
		//cout << inputc[i];
		if (inputc[i] != char(32))
		{
			xy = (inputc[i] + keyc[i]) % 91;
			//65 = A (ASCII)
			if (xy < 65)
			{
				xy = xy + 26;
			}
			char c = static_cast<char>(xy);
			cout << c;
		}
		else
		{
			cout << ' ';
		}
		
	}
	cout << '\n';
}

void decryptFile()
{
	string inputstring;
	string keystring;
	const char* inputc;
	const char* keyc;
	int xy;
	ifstream inputfile("crypt.txt");
	ifstream keyfile("key.txt");

	getline(inputfile, inputstring);
	inputfile.close();
	getline(keyfile, keystring);
	keyfile.close();
	
	transform(inputstring.begin(), inputstring.end(), inputstring.begin(), ::toupper);
	transform(keystring.begin(), keystring.end(), keystring.begin(), ::toupper);
	inputc = inputstring.c_str();
	keyc = keystring.c_str();

	for (int i = 0; i <= inputstring.length() - 1; i++)
	{
		if (inputc[i] != char(32))
		{
			xy = (inputc[i] - keyc[i]) + 65;
			//65 = A (ASCII)
			if (xy < 65)
			{
				xy = xy + 26;
			}
			char c = static_cast<char>(xy);
			cout << c;
		}
		else
		{
			cout << ' ';
		}
		
	}
	cout << '\n';
}
