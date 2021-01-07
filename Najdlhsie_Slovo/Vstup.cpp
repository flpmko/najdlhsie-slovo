#include "Vstup.h"
#include <cstring>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

Vstup::Vstup()
{
}

Vstup::Vstup(char* paNazovSuboru)
{
	if (paNazovSuboru && *paNazovSuboru != 0)
	{
		int dlzka = strlen(paNazovSuboru);
		nazovSuboru = new char[dlzka+1];
		strcpy(nazovSuboru, paNazovSuboru);
	}
	else
	this->nazovSuboru = nullptr;
}

int Vstup::zistiVelkost()
{
	int velkost = 0;
	string riadok;
	ifstream subor(this->nazovSuboru);
	while (getline(subor, riadok))
	{
		velkost++;
	}
	return velkost;
}

Vstup::~Vstup()
{
	/*delete[] this->nazovSuboru;
	this->nazovSuboru = nullptr;*/
}
