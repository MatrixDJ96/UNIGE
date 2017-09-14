#include <cmath>

#include "Punto2D.h"

Punto2D::Punto2D()
{
	_x = 0.0;
	_y = 0.0;
}

Punto2D::Punto2D(double x, double y)
{
	_x = x;
	_y = y;
}

Punto2D::Punto2D(const Punto2D& p)
{
	_x = p._x;
	_y = p._y;
}

double Punto2D::getX() const
{
	return _x;
}

double Punto2D::getY() const
{
	return _y;
}

void Punto2D::setX(int x)
{
	_x = x;
}

void Punto2D::setY(int y)
{
	_y = y;
}

double Punto2D::getDistanzaFrom(const Punto2D& p) const
{
	double dx = _x - p._x;
	double dy = _y - p._y;
	return sqrt(dx * dx + dy * dy);
}

const Punto2D& Punto2D::operator = (const Punto2D& p)
{
	if (this != &p)
	{
		_x = p._x;
		_y = p._y;
	}
	return *this;
}

Punto2D Punto2D::operator + (const Punto2D& p) const
{
	return Punto2D(_x + p._x, _y + p._y);
}

Punto2D Punto2D::operator - (const Punto2D& p) const
{
	return Punto2D(_x - p._x, _y - p._y);
}

Punto2D Punto2D::operator * (double d) const
{
	return Punto2D(_x * d, _y * d);
}

bool Punto2D::operator == (const Punto2D& p) const
{
	bool same = false;
	if (_x == p._x && _y == p._y)
	{
		same = true;
	}
	return same;
}

std::ostream& operator << (std::ostream& os, const Punto2D& p)
{
	os << "(" << p._x << ", " << p._y << ")";
	return os;
}

std::istream& operator >> (std::istream & is, Punto2D& p)
{
	is >> p._x >> p._y;
	return is;
}
