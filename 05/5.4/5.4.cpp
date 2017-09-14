#include <iostream>

int verifica(int a)
{
	if (a == 1)
	{
		return 0;
	}

	int c = 0;
	for (int b = 1; b < a; b++)
	{
		if (a % b == 0)
		{
			c++;
		}
		if (c == 1 && a == b + 1)
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	std::cout << "Inserisci alcuni valori positivi (max 100)\nPer terminare l'inserimento digita 0\n\n";
	int num[100];
	int n = 0;

	for (n; n < 100; n++)
	{
		std::cout << n + 1 << ": ";
		std::cin >> num[n];
		if (num[n] <= 0)
		{
			std::cout << '\n';
			break;
		}
	}

	int tot = 0;
	for (n; n >= 0; n--)
	{
		if (verifica(num[n]) == 1)
		{
			std::cout << "Il numero " << num[n] << " e' primo\n\n";
			tot++;
		}
	}

	if (tot == 0)
	{
		std::cout << "Non sono stati inseriti numeri primi\n\n";
	}

	return 0;
}
