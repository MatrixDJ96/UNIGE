#include "Data.h"

Data::Data()
{
	_giorno = 0;
	_mese = 0;
	_anno = 0;
}

Data::Data(int giorno, int mese, int anno)
{
	_giorno = giorno;
	_mese = mese;
	_anno = anno;
}

Data::Data(const Data& d)
{
	_giorno = d._giorno;
	_mese = d._mese;
	_anno = d._anno;
}

std::istream& operator >> (std::istream& is, Data& d)
{
	bool continua = false;
	do
	{
		std::cout << "Inserisci giorno :";
		is >> d._giorno;
		std::cout << "Inserisci mese :";
		is >> d._mese;
		std::cout << "Inserisci anno :";
		is >> d._anno;

	} while (continua == false);
	return is;
}

Data::~Data() {}
