#include <iostream>

int max_partizione(int a[], int d)
{
	int max = 0;
	int pos = 0;
	for (int i = 0; i < d; i++)
	{
		if (max == 0 || max < a[i])
		{
			max = a[i];
			pos = i;
		}
	}
	return pos;
}

void divide_et_impera(int a[], int d1)
{
	int d2 = d1 / 2;
	d1 = d1 - d2;
	int *b = new int[d1];
	int *c = new int[d2];

	for (int i = 0; i < d1; i++)
	{
		b[i] = a[i];
	}
	for (int i = 0; i < d2; i++)
	{
		c[i] = a[d1 + i];
	}

	int p1 = max_partizione(b, d1);
	int p2 = max_partizione(c, d2);
	if (b[p1] > c[p2])
	{
		a[p1] = a[d1 + d2 - 1];
		a[d1 + d2 - 1] = b[p1];
	}
	else
	{
		a[d1 + p2] = a[d1 + d2 - 1];
		a[d1 + d2 - 1] = c[p2];
	}

	if (d1 + d2 - 1 > 1) divide_et_impera(a, d1 + d2 - 1);
}

int main()
{
	int dim;
	std::cout << "Inserisci dimensione array: ";
	std::cin >> dim;

	int *array = new int[dim];
	std::cout << "\nInserisci elementi dell'array\n";
	for (int i = 0; i < dim; i++)
	{
		std::cout << i + 1 << ") ";
		std::cin >> array[i];
	}

	divide_et_impera(array, dim);

	std::cout << "\nRisultato\n";
	for (int a = 0; a < dim; a++)
	{
		std::cout << a + 1 << ") " << array[a] << '\n';
	}
	std::cout << '\n';

	return 0;
}
