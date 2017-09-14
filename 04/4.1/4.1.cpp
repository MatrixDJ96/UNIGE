#include <iostream>

int main()
{
	int num = 0;
	do {
		std::cout << "Inserisci un numero intero positivo: ";
		std::cin >> num;

		if (num < 0)
		{
			std::cout << "\nIl numero inserito e' minore di zero...\n\n";
		}
	} while (num < 0);

	long double fat = num;

	for (int x = num - 1; x > 1; x--)
	{
		fat = fat * x;
	}

	if (num == 0)
	{
		fat = 1;
	}

	std::cout.precision(10);
	std::cout << "\nIl suo fattoriale vale: " << fat << "\n\n";
	return 0;
}
