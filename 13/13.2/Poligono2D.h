#pragma once

#include "../13.1/Punto2D.h"

class Poligono2D
{
public:
	// Costruttori
	Poligono2D();
	Poligono2D(int vertici);
	Poligono2D(const Poligono2D& poligono);

	// Distruttore
	~Poligono2D();

	// Selettori
	int getNumVertici() const;

	// Altro
	double getPerimetro() const;

	// Operatori
	Poligono2D operator * (double d) const;
	const Poligono2D& operator = (const Poligono2D& poligono);
	Punto2D& operator [] (int vertice);
	friend std::ostream& operator << (std::ostream& os, const Poligono2D& poligono);
	friend std::istream& operator >> (std::istream& is, Poligono2D& poligono);

private:
	int _vertici;
	Punto2D* _punti;
};