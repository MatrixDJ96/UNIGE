#pragma once

#include <iostream>

class Punto2D
{
public:
	// Costruttori
	Punto2D();
	Punto2D(double x, double y);
	Punto2D(const Punto2D& p);

	// Selettori
	double getX() const;
	double getY() const;

	// Modificatori
	void setX(int x);
	void setY(int y);

	// Altro
	double getDistanzaFrom(const Punto2D& p) const;

	// Operatori
	const Punto2D& operator = (const Punto2D& p);
	Punto2D operator + (const Punto2D& p) const;
	Punto2D operator - (const Punto2D& p) const;
	Punto2D operator * (double d) const;
	bool operator == (const Punto2D& p) const;
	friend std::ostream& operator << (std::ostream& os, const Punto2D& p);
	friend std::istream& operator >> (std::istream& is, Punto2D& p);

private:
	double _x;
	double _y;
};
