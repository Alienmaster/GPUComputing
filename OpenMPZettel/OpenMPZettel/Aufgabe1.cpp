// Aufgabe1.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

// <>
using namespace std;

int x = 0;
int y = 0;
int z = 0;
int c = 20;
vector<vector<int>> Vektoren2D;
vector<vector<int>>::iterator it;

void main1()
{
	//it = Vektoren2D.begin();
	//Vektoren2D.insert(it, { 500, 600, 0 });
	//cout << Vektoren2D[0][1] <<  "\n";
	x = c;
		for (int i = 0; i <= c; i++)
		{
			it = Vektoren2D.end();
			Vektoren2D.insert(it, { x,y,z });
			x--;
			y++;
		}
		int l = Vektoren2D.size()-1;
		for (int i = 0; i <= l; i++)
		{
			int a = 1;
			for (int j = Vektoren2D[i][0]; j > 0; j--)
			{
				
				if (Vektoren2D[i][0] >= 1)
				{
					it = Vektoren2D.end();
					Vektoren2D.insert(it, { Vektoren2D[i][0] - a , Vektoren2D[i][1], Vektoren2D[i][2] + a });
					cout << "Hi";
				}
				a++;
			}
		}

	for (int i = 0; i < Vektoren2D.size(); i++)
	{
		for (int j = 0; j < Vektoren2D[i].size(); j++)
		{
			cout << Vektoren2D[i][j] << " ";
		}
		cout << endl;
	}
}