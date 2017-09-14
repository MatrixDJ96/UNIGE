#include <iostream>

long double potenza(double m, int n)
{
	if (m == 0)
	{
		if (n == 0)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	if (n > 0)
	{
		return m * potenza(m, n - 1);
	}
	else if (n < 0 && m != 0)
	{
		return potenza(1 / m, -n);
	}
	return 1;
}

int main()
{
	double m;
	int n;
	std::cout << "Inserisci un numero intero m: ";
	std::cin >> m;
	std::cout << "Inserisci un numero intero n: ";
	std::cin >> n;

	long double p = potenza(m, n);
	std::cout << "\nIl risultato della potenza e': ";
	if (p == -1)
	{
		std::cout << "Impossibile";
	}
	else
	{
		std::cout << p;
	}
	std::cout << "\n\n";

	return 0;
}
