#pragma once

#include <iostream>

class ComparaPrezzi
{
public:
	// Costruttori
	ComparaPrezzi();
	ComparaPrezzi(int id, int n, double* p);
	ComparaPrezzi(const ComparaPrezzi& cp);
	
	// Distruttore
	~ComparaPrezzi();
	
	// Selettori
	int getId() const;
	int getN() const;
	const double* getP() const;
	
	// Modificatori
	void setId(int id);
	void setP(double* p);
	
	// Altro
	double calcolaPrezzoMinMax(double& max);
	
	// Operatori
	friend std::istream& operator >> (std::istream& is, ComparaPrezzi& cp);
	
private:
	int _id;
	int _n;
	double* _p;
};
