#include <iostream>

int main()
{
	int d, tmp;
	std::cout << "Quanti numeri vuoi ordinare? ";
	std::cin >> d;

	int *n = new int[d];
	std::cout << "\nInserisci i numeri che vuoi ordinare:\n";
	for (int i = 0; i < d; i++)
	{
		std::cout << i + 1 << ") ";
		std::cin >> n[i];
	}

	for (int i = d - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (n[j] > n[j + 1])
			{
				tmp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = tmp;
			}
		}
	}

	std::cout << "\nNumeri riordinati: ";
	for (int i = 0; i < d; i++)
	{
		std::cout << n[i];
		if (i < d - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n\n";
	return 0;
}