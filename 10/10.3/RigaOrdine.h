#pragma once

#include "Stringhe.h"

class RigaOrdine
{
public:
	// Costruttori
	RigaOrdine();
	RigaOrdine(int codice, const char* descrizione, int pezzi_ordinati, double prezzo);
	RigaOrdine(const RigaOrdine& ro);

	// Selettori
	int getCodice() const;
	char* getDescrizione() const;
	int getPezziOrdinati() const;
	double getPrezzo() const;

	// Modificatori
	void setCodice(int codice);
	void setDescrizione(const char* descrizione);
	void setPezziOrdinati(int pezzi_ordinati);
	void setPrezzo(double prezzo);

	// Altro
	double costo_totale() const;

	// Operatori
	friend std::ostream& operator << (std::ostream& os, const RigaOrdine& ro);
	friend std::istream& operator >> (std::istream& is, RigaOrdine& ro);

	// Distruttore
	~RigaOrdine();
private:
	int _codice;
	char* _descrizione;
	int _pezzi_ordinati;
	double _prezzo;
};
