#include "Poligono2D.h"

Poligono2D::Poligono2D()
{
	_vertici = 0;
	_punti = NULL;
}

Poligono2D::Poligono2D(int vertici)
{
	if (vertici > 0)
	{
		_vertici = vertici;
		_punti = new Punto2D[_vertici];
	}
	else
	{
		_vertici = 0;
		_punti = NULL;
	}
}

Poligono2D::Poligono2D(const Poligono2D& poligono)
{
	if (poligono._vertici > 0)
	{
		_vertici = poligono._vertici;
		_punti = new Punto2D[_vertici];
		for (int i = 0; i < _vertici; i++)
		{
			_punti[i] = poligono._punti[i];
		}
	}
	else
	{
		_vertici = 0;
		_punti = NULL;
	}
}

Poligono2D::~Poligono2D()
{
	if (_punti != NULL)
	{
		delete[] _punti;
		_punti = NULL;
	}
}

int Poligono2D::getNumVertici() const
{
	return _vertici;
}

double Poligono2D::getPerimetro() const
{
	if (_vertici > 1)
	{
		double perimetro = 0;
		for (int i = 0; i < _vertici; i++)
		{
			perimetro += _punti[i].getDistanzaFrom(_punti[i + 1]);
		}
		return perimetro;
	}
	else
	{
		return 0.0;
	}
}

Poligono2D Poligono2D::operator * (double d) const
{
	if (_vertici > 0)
	{
		Poligono2D result(_vertici);
		for (int i = 0; i < _vertici; i++)
		{
			result._punti[i] = _punti[i] * d;
		}
		return result;
	}
	else
	{
		return Poligono2D();
	}
}

const Poligono2D& Poligono2D::operator = (const Poligono2D& poligono)
{
	if (this != &poligono && poligono._vertici > 0)
	{
		_vertici = poligono._vertici;
		if (_punti != NULL)
		{
			delete[] _punti;
			_punti = NULL;
		}
		_punti = new Punto2D[_vertici];
		for (int i = 0; i < _vertici; i++)
		{
			_punti[i] = poligono._punti[i];
		}
	}
	return *this;
}

Punto2D& Poligono2D::operator [] (int vertice)
{
	if (vertice < _vertici)
	{
		return _punti[vertice];
	}
	else
	{
		return Punto2D(0, 0);
	}
}

std::ostream& operator << (std::ostream& os, const Poligono2D& poligono)
{
	if (poligono._vertici > 0)
	{
		for (int i = 0; i < poligono._vertici; i++)
		{
			os << poligono._punti[i];
			if (i < poligono._vertici - 1)
			{
				os << ' ';
			}
		}
	}
	else
	{
		os << "Il Poligono2D non ha vertici\n";
	}
	return os;
}

std::istream& operator >> (std::istream& is, Poligono2D& poligono)
{
	if (poligono._vertici > 0)
	{
		for (int i = 0; i < poligono._vertici; i++)
		{
			std::cout << i + 1 << ": ";
			is >> poligono[i]; // uso l'operatore []
		}
	}
	else
	{
		std::cout << "Il Poligono2D non ha vertici\n";
	}
	return is;
}
