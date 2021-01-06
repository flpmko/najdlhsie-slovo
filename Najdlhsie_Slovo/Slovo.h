#pragma once
class Slovo
{
private:
	char* text = nullptr;
	short dlzka = 0;
public:
	Slovo();
	Slovo(char* paText);
	Slovo(const Slovo& zdroj);
	Slovo operator = (const Slovo& zdroj);
	inline char* getText() { return this->text; };
	inline short getDlzka() { return this->dlzka; };
	void vypis();
	~Slovo();
};

