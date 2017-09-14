#include <iostream>
#include <math.h>

int main()
{
	double a, b, c;

	std::cout << "Scrivi i valori dei lati di un triangolo: ";
	std::cin >> a >> b >> c;

	if (a + b < c || a + c < b || b + c < a)
	{
		std::cout << "\nIl triangolo i cui lati misurano " << a << ", " << b << " e " << c << " non esiste\n\n";
	}
	else
	{
		double p = (a + b + c) / 2;
		double A = sqrt(p * (p - a) * (p - b) * (p - c));
		std::cout << "\nIl semiperimetro equivale a " << p << '\n';
		std::cout << "L'area del triangolo equivale a " << A << "\n\n";
	}

	return 0;
}
