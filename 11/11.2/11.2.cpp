#include <iostream>
#include <math.h>

double fattoriale(double d)
{
	if (d == 0)
	{
		return 1;
	}
	else if (d > 0)
	{
		return d * fattoriale(d - 1);
	}
	else if (d < 0)
	{
		return 0.0;
	}
}

double Taylor(double d, int i)
{
	if (i < 0)
	{
		return 0.0;
	}
	else
	{
		double risultato = pow(-1, i) * pow(d, 2 * i + 1) / fattoriale(2 * i + 1);
		return risultato + Taylor(d, i - 1);
	}
}

int main()
{
	double rad;
	int n;
	do {
		std::cout << "Inserisci numero in radianti: ";
		std::cin >> rad;
		if (rad < -1 || rad > 1) std::cout << "\nL'angolo non e' valido. Riprova\n\n";
	} while (rad < -1 || rad > 1);

	do {
		std::cout << "Inserisci il termine n-esimo dello sviluppo di Taylor: ";
		std::cin >> n;
		if (n < 0) std::cout << "\nIl termine n-esimo non e' valido. Riprova\n\n";
	} while (n < 0);

	std::cout << "\nRisultato: " << Taylor(rad, n) << "\n\n";

	return 0;
}
