#pragma once
class Vstup
{private:
	char* nazovSuboru = nullptr;
public:
	Vstup();
	Vstup(char* paNazovSuboru);
	int zistiVelkost();
	inline char* getNazovSuboru() { return this->nazovSuboru; };
	~Vstup();
};

