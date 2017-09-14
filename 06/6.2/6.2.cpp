#include <iostream>

int Fibonacci(int fibo[], int num)
{
	int f = 0;
	int g = 1;
	int r = 0;
	for (int i = 0; i < num; i++)
	{
		if (f == 0 && i>0) f = 1;
		fibo[i] = f + g;
		g = f;
		f = fibo[i];
		r = i;
	}
	return r;
}

int main()
{
	int n = 0;
	int j[100];

	std::cout << "Inserisci la \'n\' della successione di Fibonacci: ";
	std::cin >> n;

	int a = Fibonacci(j, n);

	std::cout << "\nSuccessione richiesta -> ";
	for (int i = 0; i <= a; i++)
	{
		std::cout << j[i];
		if (i != a) std::cout << ", ";
	}

	std::cout << "\n\n";
	return 0;
}
