#pragma once

#include <iostream>

class Data
{
public:
	// Costruttori
	Data();
	Data(int giorno, int mese, int anno);
	Data(const Data& d);

	// Operatori
	friend std::istream& operator >> (std::istream& is, Data& d);

	// Distruttore
	~Data();
private:	
	int _giorno;
	int _mese;
	int _anno;
};
