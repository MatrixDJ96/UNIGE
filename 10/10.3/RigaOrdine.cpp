#include "RigaOrdine.h"

RigaOrdine::RigaOrdine()
{
	_codice = 0;
	_descrizione = setStr("Sconosciuta");
	_pezzi_ordinati = 0;
	_prezzo = 0.0;
}

RigaOrdine::RigaOrdine(int codice, const char* descrizione, int pezzi_ordinati, double prezzo)
{
	_codice = codice;
	_descrizione = setStr(descrizione);
	_pezzi_ordinati = pezzi_ordinati;
	_prezzo = prezzo;
}

RigaOrdine::RigaOrdine(const RigaOrdine& ro)
{
	_codice = ro._codice;
	_descrizione = setStr(ro._descrizione);
	_pezzi_ordinati = ro._pezzi_ordinati;
	_prezzo = ro._prezzo;
}

int RigaOrdine::getCodice() const
{
	return _codice;
}

char* RigaOrdine::getDescrizione() const
{
	return _descrizione;
}

int RigaOrdine::getPezziOrdinati() const
{
	return _pezzi_ordinati;
}

double RigaOrdine::getPrezzo() const
{
	return _prezzo;
}

void RigaOrdine::setCodice(int codice)
{
	_codice = codice;
}

void RigaOrdine::setDescrizione(const char* descrizione)
{
	_descrizione = setStr(descrizione);
}

void RigaOrdine::setPezziOrdinati(int pezzi_ordinati)
{
	_pezzi_ordinati = pezzi_ordinati;
}

void RigaOrdine::setPrezzo(double prezzo)
{
	_prezzo = prezzo;
}

double RigaOrdine::costo_totale() const
{
	return _pezzi_ordinati * _prezzo;
}

std::ostream& operator << (std::ostream& os, const RigaOrdine& ro)
{
	os <<
		"Riga d'ordine\nCodice: " << ro._codice <<
		"\nDescrizione: " << ro._descrizione <<
		"\nPezzi ordinati: " << ro._pezzi_ordinati <<
		"\nPrezzo ordine: " << ro.costo_totale();

	return os;
}

std::istream& operator >> (std::istream& is, RigaOrdine& ro)
{
	std::cout << "Riga d'ordine\nCodice: ";
	ro._codice = strToInt(insertStr(is));

	std::cout << "Descrizione: ";
	ro._descrizione = insertStr(is);

	std::cout << "Pezzi ordinati: ";
	ro._pezzi_ordinati = strToInt(insertStr(is));

	std::cout << "Prezzo del singolo oggetto: ";
	ro._prezzo = strToDouble(insertStr(is));

	return is;
}

RigaOrdine::~RigaOrdine()
{
	if (_descrizione != NULL)
	{
		delete[] _descrizione;
		_descrizione = NULL;
	}
}
