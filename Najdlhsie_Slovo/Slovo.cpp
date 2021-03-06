#include "Slovo.h"
#include <cstring>
#include <iostream>

using namespace std;

Slovo::Slovo()
{
}

Slovo::Slovo(char* paText)
{
	if (paText && *paText != 0)
	{
		int velkost = strlen(paText);
		if (velkost < 51)
		{
			text = new char[velkost + 1];
			strcpy(text, paText);
			this->dlzka = strlen(this->text);
		}
		else
		{
			cout << "SLOVO JE PRILIS DLHE!\n"
				<< "------------------------------------------------\n";
			text = new char[2];
			strcpy(text, "");
			this->dlzka = strlen(this->text);
		}
	}
}

Slovo::Slovo(const Slovo& zdroj)
{
	int velkost = strlen(zdroj.text);
	if (velkost < 51)
	{
		text = new char[velkost + 1];
		strcpy(text, zdroj.text);
		this->dlzka = strlen(this->text);
	}
	else
	{
		cout << "SLOVO JE PRILIS DLHE!\n"
			<< "------------------------------------------------\n";
		text = new char[2];
		strcpy(text, "");
		this->dlzka = strlen(this->text);
	}
}

Slovo Slovo::operator=(const Slovo& zdroj)
{
	if (this != &zdroj)
	{
		Slovo::~Slovo();

		int velkost = strlen(zdroj.text);
		if (velkost < 51)
		{
			text = new char[velkost + 1];
			strcpy(text, zdroj.text);
			this->dlzka = strlen(this->text);
		}
		else
		{
			cout << "SLOVO JE PRILIS DLHE!\n"
				<< "------------------------------------------------\n";
			text = new char[2];
			strcpy(text, "");
			this->dlzka = strlen(this->text);
		}
	}
	return Slovo();
}

void Slovo::vypis()
{
	cout << "SLOVO: " << this->text << ", DLZKA: " << this->dlzka << endl;
}

Slovo::~Slovo()
{
	delete[] text;
	text = nullptr;
	dlzka = 0;
}
