// OpenMPZettel.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int x = 0;
int y = 0;
int z = 0;
int c = 20;

int main()
{
	x = c;
	for (int i = 0; x >= 0; i++)
	{
		y = 0;
		if ((x + y + z) < c)
		{
			for (int j = 0; y < c; j++)
			{
				z = 0;
				if ((x + y + z) < c)
				{
					for (int k = 0; z < c; k++)
					{
						if ((x + y + z) == c)
						{
							cout << "z:" << z << " " << "y:" << " " << y << " " << "x:" << x << " "<< "\n";
						}
						z++;
					}
				
					
				}
				y++;
				
				//cout << "y:" << y << "\n";
			}

			
		}
		x--;
		
		//cout << "x:" << x << "\n";
	}
	return 0;
}

// <>

