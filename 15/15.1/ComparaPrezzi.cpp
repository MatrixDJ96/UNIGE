#include "ComparaPrezzi.h"

ComparaPrezzi::ComparaPrezzi()
{
	_id = 0;
	_n = 0;
	_p = NULL;
}

ComparaPrezzi::ComparaPrezzi(int id, int n, double* p)
{
	if (n > 0) {
		_id = id;
		_n = n;
		_p = new double[_n];
		for (int i = 0; i < n; n++) {
			_p[i] = p[i];
		}
	}
	else {
		_id = 0;
		_n = 0;
		_p = NULL;
		std::cout << "\nImpossibile inizializzare la classe con i parametri indicati\n";
	}
}

ComparaPrezzi::ComparaPrezzi(const ComparaPrezzi& cp)
{
	if (cp._n > 0) {
		_id = cp._id;
		_n = cp._n;
		_p = new double[_n];
		for (int i = 0; i < _n; _n++) {
			_p[i] = cp._p[i];
		}
	}
	else {
		_id = 0;
		_n = 0;
		_p = NULL;
		std::cout << "\nImpossibile inizializzare la classe con il costruttore di copia\n";
	}
}

ComparaPrezzi::~ComparaPrezzi()
{
	if (_p != NULL) {
		delete[] _p;
		_p = NULL;
	}
}

int ComparaPrezzi::getId() const
{
	return _id;
}

int ComparaPrezzi::getN() const
{
	return _n;
}

const double* ComparaPrezzi::getP() const
{
	return _p;
}

void ComparaPrezzi::setId(int id)
{
	_id = id;
}

void ComparaPrezzi::setP(double* p)
{
	for (int i = 0; i < _n; i++) {
		_p[i] = p[i];
	}
}

double ComparaPrezzi::calcolaPrezzoMinMax(double& max)
{
	double min = -1;
	max = -1;
	
	for (int i = 0; i < _n; i++) {
		if (min == -1 || _p[i] < min) {
			min = _p[i];
		}
		if (max == -1 || _p[i] > max) {
			max = _p[i];
		}
	}
	
	return min;
}

std::istream& operator >> (std::istream& is, ComparaPrezzi& cp)
{
	bool continua = false;
		std::cout << "Inserisci il numero dei fornitori: ";
	do {
		is >> cp._n;
		if (cp._n > 0) {
			if (cp._p != NULL) {
				delete[] cp._p;
				cp._p = NULL;
			}
			cp._p = new double[cp._n];
			std::cout << '\n';
			for (int i = 0; i < cp._n; i++) {
				std::cout << "Prezzo " << i + 1 << ": ";
				is >> cp._p[i];
				if (cp._p[i] < 0) {
					std::cout << "\nPrezzo non valido. Riprova\n\n";
					i--;
				}
			}
			continua = true;
		}
		else {
			std::cout << "\nNumero fornitori non valido. Riprova\n\n";
			std::cout << "Inserisci il numero dei fornitori: ";
		}
	} while (continua == false);
	
	return is;
}
