// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void encrypt();
void decrypt();
void encryptFile();
void decryptFile();

int main()
{
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
	}
	return 0;
}

void encrypt()
{
	string input;
	string keyphrase;
	const char* inputc;
	const char* keyphrasec;
	int xy;

	cout << "Wort eingeben\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::toupper);
	cout << "Schluessel eingeben\n";
	cin >> keyphrase;
	transform(keyphrase.begin(), keyphrase.end(), keyphrase.begin(), ::toupper);
	inputc = input.c_str();
	keyphrasec = keyphrase.c_str();

	for (int i = 0; i <= input.length() - 1; i++)
	{
		xy = (inputc[i] + keyphrasec[i]) % 91;
		//65 = A (ASCII)
		if (xy < 65)
		{
			xy = xy + 26;
		}
		char c = static_cast<char>(xy);
		cout << c;
	}
}

void decrypt()
{
	string input;
	string keyphrase;
	const char* inputc;
	const char* keyphrasec;
	int xy;

	cout << "Wort eingeben\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::toupper);
	cout << "Schluessel eingeben\n";
	cin >> keyphrase;
	transform(keyphrase.begin(), keyphrase.end(), keyphrase.begin(), ::toupper);
	inputc = input.c_str();
	keyphrasec = keyphrase.c_str();

	for (int i = 0; i <= input.length() - 1; i++)
	{
		if (inputc[i] != char(32))
		{
		xy = (inputc[i] - keyphrasec[i]) + 65;
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

	if (inputfile.is_open())
	{
		while (getline(inputfile, inputstring))
		{
		}
		inputfile.close();

	}

	if (keyfile.is_open())
	{
		while (getline(keyfile, keystring))
		{
		}
		keyfile.close();

	}

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

	if (inputfile.is_open())
	{
		while (getline(inputfile, inputstring))
		{
		}
		inputfile.close();

	}

	if (keyfile.is_open())
	{
		while (getline(keyfile, keystring))
		{
		}
		keyfile.close();

	}

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
}
