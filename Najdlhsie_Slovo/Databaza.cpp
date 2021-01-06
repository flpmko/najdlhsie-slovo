#include "Databaza.h"
#include <fstream>
#include <iostream>

using namespace std;

Databaza::Databaza()
{
}

Databaza::Databaza(int paVelkost)
{
	if (paVelkost > 0)
	{
		this->velkost = paVelkost;
		this->zoznam = new Slovo* [paVelkost];
	}
	else
	{
		this->velkost = 0;
		this->zoznam = nullptr;
	}
}

void Databaza::nacitaj(Vstup subor)
{
	ifstream input;
	input.open(subor.getNazovSuboru());
	if (input.is_open())
	{
		string slovo;
		int i = 0;

		while (!input.eof())
		{
			input >> slovo;
			this->zoznam[i] = new Slovo((char*)slovo.c_str());
			i++;
		}
	}
	input.close();
}

void Databaza::zoradZostupne()
{
	for (int i = 0; i < velkost - 1; i++)
	{
		for (int j = 0; j < velkost - i - 1; j++)
		{
			if (this->zoznam[j]->getDlzka() < this->zoznam[j + 1]->getDlzka())
			{
				vymen(*this->zoznam[j], *this->zoznam[j + 1]);
			}
		}
	}
}

void Databaza::zoradVzostupne()
{
	for (int i = 0; i < velkost - 1; i++)
	{
		for (int j = 0; j < velkost - i - 1; j++)
		{
			if (this->zoznam[j]->getDlzka() > this->zoznam[j + 1]->getDlzka())
			{
				vymen(*this->zoznam[j], *this->zoznam[j + 1]);
			}
		}
	}
}

void Databaza::vymen(Slovo& a, Slovo& b)
{
	Slovo c = a;
	a = b;
	b = c;
}

void Databaza::vypis()
{
	if (this->zoznam != nullptr)
	{
		for (int i = 0; i < this->velkost; i++)
		{
			this->zoznam[i]->vypis();
		}
	}
	else
		cout << "PRAZDNY ZOZNAM!" << endl;
}

void Databaza::vypis(int pozicia)
{
	if (this->zoznam != nullptr)
	{
		if (0 <= pozicia <= this->velkost)
		{
			this->zoznam[pozicia]->vypis();
		}
		else
			cout << "POZICIA NEEXISTUJE!" << endl;
	}
	else
		cout << "PRAZDNY ZOZNAM!" << endl;
}

Databaza::~Databaza()
{
	for (int i = 0; i < this->velkost; i++) {
		delete this->zoznam[i];
	}
	delete[] zoznam;
}
