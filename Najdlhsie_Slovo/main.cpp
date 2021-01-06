#include "Vstup.h"
#include "Databaza.h"
#include <iostream>

#define _CRT_SECURE_NO_DEPRECATE

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Vstup subor((char*)"data.txt");
	Databaza databaza(subor.zistiVelkost());
	databaza.nacitaj(subor);
	databaza.vypis();

	cout << "-----------------------------------------------\n" 
		<<"TRI NAJDLHSIE SLOVA:\n" 
		<< "-----------------------------------------------\n";
	databaza.zoradZostupne();
	for (int i = 0; i < 3; i++)
	{
		databaza.vypis(i);
	}

	return 0;
}