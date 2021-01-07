#pragma once
class Vstup
{private:
	char* nazovSuboru = nullptr;
public:
	Vstup();
	Vstup(char* paNazovSuboru);
	Vstup(const Vstup& zdroj);
	Vstup operator=(const Vstup& zdroj);
	int zistiVelkost();
	inline char* getNazovSuboru() { return this->nazovSuboru; };
	~Vstup();
};

