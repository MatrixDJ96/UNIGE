#include <iostream>

const int max = 100;

double funzione(double* x, double* y, int n)
{
	double ps = 0;

	for (int a = 0; a < n; a++)
	{
		ps += *(x + a) * *(y + a);
	}

	return ps;
}

int main()
{
	double y[max];
	double x[max];
	int d;

	do {
		std::cout << "Inserisci la dimensione degli array che vuoi creare (max 100): ";
		std::cin >> d;
		if (d <= 0)
		{
			std::cout << "L'array deve essere maggiore di 0\n";
		}
		else if (d > max)
		{
			std::cout << "L'array deve essere minore uguale di 100\n";
		}
		std::cout << '\n';
	} while (d <= 0 || d > max);

	std::cout << "Inserisci un array x di " << d << " elementi:\n";
	for (int i = 0; i < d; i++)
	{
		std::cout << i + 1 << ") ";
		std::cin >> x[i];
	}

	std::cout << "\nInserisci un array y di " << d << " elementi:\n";
	for (int i = 0; i < d; i++)
	{
		std::cout << i + 1 << ") ";
		std::cin >> y[i];
	}

	std::cout << "\nIl risultato del prodotto scalare vale " << funzione(x, y, d) << "\n\n";

	return 0;
}
