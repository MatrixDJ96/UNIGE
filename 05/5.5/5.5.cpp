#include <iostream>
#include <math.h>

int funzione(int n, int b, int &e, int &m)
{
	if (n < 0 || b <= 1) return -1;

	for (int a = 1; a > 0; a++)
	{
		m = int(pow(b, a));
		if (m > n)
		{
			e = a;
			return 0;
		}
	}
}

int main()
{
	int n, b, e, m;
	std::cout << "Inserisci 2 numeri interi positivi n e b\n\nn: ";
	std::cin >> n;
	std::cout << "b: ";
	std::cin >> b;

	if (funzione(n, b, e, m) == 0)
	{
		std::cout << "\nLa piu' piccola potenza di b maggiore di n vale " << m << " (" << b << "^" << e << ")\n\n";
	}
	else
	{
		std::cout << "\nNon posso eseguire le operazioni richieste con i numeri inseriti\n\n";
	}

	return 0;
}
