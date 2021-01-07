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

Vstup::Vstup(const Vstup& zdroj)
{
	if (this != &zdroj)
	{
		int dlzka = strlen(zdroj.nazovSuboru);
		nazovSuboru = new char[dlzka + 1];
		strcpy(nazovSuboru, zdroj.nazovSuboru);
	}
}

Vstup Vstup::operator=(const Vstup& zdroj)
{
	if (this != &zdroj)
	{
		Vstup::~Vstup();
		int dlzka = strlen(zdroj.nazovSuboru);
		nazovSuboru = new char[dlzka + 1];
		strcpy(nazovSuboru, zdroj.nazovSuboru);
	}
	return *this;
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
	delete[] nazovSuboru;
	this->nazovSuboru = nullptr;
}
