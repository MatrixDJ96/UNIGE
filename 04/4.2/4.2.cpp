#include <iostream>

const int nmax = 100;

int main()
{
	int n = 0;
	double num[nmax];
	std::cout << "Quanti numeri vuoi inserire (max " << nmax << ")? ";
	std::cin >> n;
	if (n > nmax)
	{
		std::cout << "\nNon ho voglia di calcore la media di " << n << " elementi\n\n";
		return 1;
	}
	else if (n < 1)
	{
		std::cout << "\nDevi inserire almeno un numero\n\n";
		return 1;
	}
	double somma = 0;
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ": ";
		std::cin >> num[i];
		somma = somma + num[i];
	}
	double media = somma / double(n);
	std::cout << "\nLa media dei numeri inseriti vale: " << media << "\n\n";
	return 0;
}
