#include <iostream>
#include <stdlib.h>

int main()
{
	int a = 0;
	int f = 0;
	int n = 0;
	int g = 1;
	int fibo[100];

	std::cout << "Inserisci la \'n\' della successione di Fibonacci: ";
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		if (f == 0 && i > 0) f = 1;
		fibo[i] = f + g;
		g = f;
		f = fibo[i];
		a = i;
	}

	std::cout << "\nSuccessione richiesta -> ";
	for (int i = 0; i <= a; i++)
	{
		std::cout << fibo[i];
		if (i != a) std::cout << ", ";
	}

	std::cout << "\n\n";
	system("pause");
	return 0;
}
