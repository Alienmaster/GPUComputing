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
	string inputfileName;
	string keyfileName;
	string inputstring;
	string keystring;
	const char* inputc;
	const char* keyc;
	int xy;

	cout << "Bitte geben sie den Dateinamen der Klartext Datei an:\n";
	cin >> inputfileName;
	cout << "Bitte geben sie den Dateinamen der Schluesseldatei an:\n";
	cin >> keyfileName;

	ifstream inputfile(inputfileName);
	ifstream keyfile(keyfileName);
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
	string inputfileName;
	string keyfileName;
	string inputstring;
	string keystring;
	const char* inputc;
	const char* keyc;
	int xy;
	cout << "Bitte geben sie den Dateinamen der verschluesselten Datei an:\n";
	cin >> inputfileName;
	cout << "Bitte geben sie den Dateinamen der Schluesseldatei an:\n";
	cin >> keyfileName;
	ifstream inputfile(inputfileName);
	ifstream keyfile(keyfileName);

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
