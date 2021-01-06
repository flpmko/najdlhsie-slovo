#pragma once
#include "Vstup.h"
#include "Slovo.h"

class Databaza
{private:
	Slovo** zoznam = nullptr;
	int velkost = 0;
public:
	Databaza();
	Databaza(int paVelkost);
	void nacitaj(Vstup subor);
	void zoradZostupne();
	void zoradVzostupne();
	void vymen(Slovo& a, Slovo& b);
	void vypis();
	void vypis(int pozicia);
	inline int getVelkost()
	{
		return this->velkost;
	};
	~Databaza();
};

