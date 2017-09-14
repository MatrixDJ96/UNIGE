#pragma once

#include "..\10.3\RigaOrdine.h"

class Ordine
{
public:
	// Costruttori
	Ordine();
	Ordine(int numero_ordine, const char* nome, const char* cognome, const char* indirizzo, const char* codice_fiscale);
	Ordine(const Ordine& o);

	// Selettori
	int getNumeroOrdine() const;
	char* getNome() const;
	char* getCognome() const;
	char* getIndirizzo() const;
	char* getCodiceFiscale() const;
	int getNumeroRigheOrdine() const;
	RigaOrdine getRigaOrdinefromIndice(int indice) const;
	RigaOrdine getRigaOrdinefromCodice(int codice) const;

	// Modificatori
	void setNumeroOrdine(int numero_ordine);
	void setNome(const char* nome);
	void setCognome(const char* cognome);
	void setIndirizzo(const char* indirizzo);
	void setCodiceFiscale(const char* codice_fiscale);
	void insertRigaOrdine();

	// Altro
	double costo_totale() const;

	// Operatori
	friend std::ostream& operator << (std::ostream& os, const Ordine& o);
	friend std::istream& operator >> (std::istream& is, Ordine& o);

	// Distruttore
	~Ordine();
private:
	int _numero_ordine;
	char* _nome;
	char* _cognome;
	char* _indirizzo;
	char* _codice_fiscale;
	int _num_ro;
	RigaOrdine* _ro;
};
