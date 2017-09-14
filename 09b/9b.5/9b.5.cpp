#include <iostream>

const int n = 3;

int funzione(int A[n][n], int **b)
{
	for (int a = 0; a < n; a++)
	{
		*(b + a) = NULL;
	}

	int somma = 0;
	int pos = -1;
	for (int a = 0; a < n; a++) // riga
	{
		for (int b = 0; b < n; b++) // colonna
		{
			somma += A[a][b];
		}
		if (somma < 0)
		{
			pos++;
			b[pos] = *(A + a);
		}
		somma = 0;
	}
	return pos;
}

int main()
{
	int A[n][n];
	int *b[n];

	std::cout << "Inserisci gli elementi della matrice " << n << "x" << n << ":\n";
	for (int a = 0; a < n; a++) // riga
	{
		std::cout << a + 1 << ") ";
		for (int b = 0; b < n; b++) // colonna
		{
			std::cin >> A[a][b];
		}
	}

	int pos = funzione(A, b);

	if (pos != -1)
	{
		std::cout << "\nRighe la cui la somma degli elementi risulti negativa:\n";
		for (int a = 0; a <= pos; a++)
		{
			std::cout << a + 1 << ") ";
			for (int c = 0; c < n; c++)
			{
				std::cout << *(*(b + a) + c);
				if (c + 1 != n)
				{
					std::cout << ", ";
				}
			}
			std::cout << '\n';
		}
	}
	else
	{
		std::cout << "\nNon sono state trovate righe in cui la somma degli elementi risulti negativa\n";
	}
	std::cout << '\n';

	return 0;
}
