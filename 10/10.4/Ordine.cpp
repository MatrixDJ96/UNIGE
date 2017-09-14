#include "Ordine.h"

Ordine::Ordine()
{
	_numero_ordine = 0;
	const char _default[12] = "Sconosciuto";
	_nome = setStr(_default);
	_cognome = setStr(_default);
	_indirizzo = setStr(_default);
	_codice_fiscale = setStr(_default);
	_num_ro = 0;
	_ro = NULL;
}

Ordine::Ordine(int numero_ordine, const char* nome, const char* cognome, const char* indirizzo, const char* codice_fiscale)
{
	_numero_ordine = numero_ordine;
	_nome = setStr(nome);
	_cognome = setStr(cognome);
	_indirizzo = setStr(indirizzo);
	_codice_fiscale = setStr(codice_fiscale);
	_num_ro = 0;
	_ro = NULL;
}

Ordine::Ordine(const Ordine& o)
{
	_numero_ordine = o._numero_ordine;
	_nome = setStr(o._nome);
	_cognome = setStr(o._cognome);
	_indirizzo = setStr(o._indirizzo);
	_codice_fiscale = setStr(o._codice_fiscale);
	if (o._ro != NULL)
	{
		_num_ro = o._num_ro;
		_ro = new RigaOrdine[_num_ro];
		for (int i = 0; i < _num_ro; i++)
		{
			_ro[i] = o._ro[i];
		}
	}
	else
	{
		_num_ro = 0;
		_ro = NULL;
	}
}

int Ordine::getNumeroOrdine() const
{
	return _numero_ordine;
}

char* Ordine::getNome() const
{
	return _nome;
}

char* Ordine::getCognome() const
{
	return _cognome;
}

char* Ordine::getIndirizzo() const
{
	return _indirizzo;
}

char* Ordine::getCodiceFiscale() const
{
	return _codice_fiscale;
}

int Ordine::getNumeroRigheOrdine() const
{
	return _num_ro;
}

RigaOrdine Ordine::getRigaOrdinefromIndice(int indice) const
{
	if (_ro != NULL)
	{
		if (indice >= 0 && indice < _num_ro)
		{
			return _ro[indice];

		}
	}
	std::cout << "Impossibile trovare la riga d'ordine desiderata\n";
	return RigaOrdine();
}

RigaOrdine Ordine::getRigaOrdinefromCodice(int codice) const
{
	if (_ro != NULL)
	{
		for (int i = 0; i < _num_ro; i++)
		{
			if (_ro[i].getCodice() == codice)
			{
				return _ro[i];
			}
		}
	}
	std::cout << "Impossibile trovare la riga d'ordine desiderata\n";
	return RigaOrdine();
}

void Ordine::setNumeroOrdine(int numero_ordine)
{
	_numero_ordine = numero_ordine;
}

void Ordine::setNome(const char* nome)
{
	_nome = setStr(nome);
}

void Ordine::setCognome(const char* cognome)
{
	_cognome = setStr(cognome);
}

void Ordine::setIndirizzo(const char* indirizzo)
{
	_indirizzo = setStr(indirizzo);
}

void Ordine::setCodiceFiscale(const char* codice_fiscale)
{
	_codice_fiscale = setStr(codice_fiscale);
}

void Ordine::insertRigaOrdine()
{
	if (_ro != NULL)
	{
		_num_ro++;
		RigaOrdine* new_ro = new RigaOrdine[_num_ro];
		for (int i = 0; i < _num_ro - 1; i++)
		{
			new_ro[i] = _ro[i];
		}
		delete[] _ro;
		_ro = new_ro;
	}
	else
	{
		_num_ro = 1;
		_ro = new RigaOrdine[_num_ro];
	}
	_ro[_num_ro - 1].setCodice(strToInt(insertStr()));
	_ro[_num_ro - 1].setDescrizione(insertStr());
	_ro[_num_ro - 1].setPezziOrdinati(strToInt(insertStr()));
	_ro[_num_ro - 1].setPrezzo(strToDouble(insertStr()));
}

double Ordine::costo_totale() const
{
	double totale = 0.0;
	if (_ro != NULL)
	{
		for (int i = 0; i < _num_ro; i++)
		{
			totale += _ro[i].costo_totale();
		}
	}
	return totale;
}


std::ostream& operator << (std::ostream& os, const Ordine& o)
{

	os <<
		"Ordine\nNumero ordine: " << o._numero_ordine <<
		"\nNome: " << o._nome <<
		"\nCognome: " << o._cognome <<
		"\nIndirizzo: " << o._indirizzo <<
		"\nCodice fiscale: " << o._codice_fiscale <<
		"\nNumero righe d'ordine: " << o._num_ro;

	if (o._num_ro > 0)
	{
		os << "\n\n--------------------------------";
		for (int i = 0; i < o._num_ro; i++)
		{
			os << '\n' << o._ro[i] << '\n';
		}
		os << "--------------------------------";
	}

	return os;
}

std::istream& operator >> (std::istream& is, Ordine& o)
{
	std::cout << "Ordine\nNumero ordine: ";
	o._numero_ordine = strToInt(insertStr(is));

	std::cout << "Nome: ";
	o._nome = insertStr(is);

	std::cout << "Cognome: ";
	o._cognome = insertStr(is);

	std::cout << "Indirizzo: ";
	o._indirizzo = insertStr(is);

	std::cout << "Codice fiscale: ";
	o._codice_fiscale = insertStr(is);

	return is;
}

Ordine::~Ordine()
{
	if (_nome != NULL)
	{
		delete[] _nome;
		_nome = NULL;
	}
	if (_cognome != NULL)
	{
		delete[] _cognome;
		_cognome = NULL;
	}
	if (_indirizzo != NULL)
	{
		delete[] _indirizzo;
		_indirizzo = NULL;
	}
	if (_codice_fiscale != NULL)
	{
		delete[] _codice_fiscale;
		_codice_fiscale = NULL;
	}
	if (_ro != NULL)
	{
		delete[] _ro;
		_ro = NULL;
	}
}
