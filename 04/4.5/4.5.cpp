#include <iostream>

void funzione(int& ber)
{
	std::cout << "Inserisci un numero intero positivo: ";
	std::cin >> ber;
}

int main()
{
	int num;
	funzione(num);
	while (num <= 0)
	{
		funzione(num);
	}


	int divisori[512];
	std::cout << "\nDivisori di " << num << ": ";

	int b = 0;
	for (int a = 1; a <= num; a++)
	{
		if (num % a == 0)
		{
			divisori[b] = a;
			std::cout << divisori[b];
			b++;
			if (a < num) std::cout << ", ";
		}
	}

	std::cout << "\n\n";
	return 0;
}
