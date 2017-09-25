#include <iostream>

const int dim = 256;

int dim_size(char c[])
{
	int b = 1;
	for (int a = 0; c[a] != '\0'; a++)
	{
		b++;
	}
	return b;
}

int main()
{
	char str1[dim];
	char str2[dim];

	std::cout << "Inserisci una stringa: ";
	std::cin.getline(str1, dim, '\n');

	std::cout << "Inserisci un'altra stringa: ";
	std::cin.getline(str2, dim, '\n');

	int dim1 = dim_size(str1) - 1;
	int dim2 = dim_size(str2) - 1;

	int occ = 0; // numero occorrenze
	int pos = -1; // posizione prima occorrenza

	if (dim1 >= dim2)
	{
		int b = 0; 
		for (int a = 0; a <= dim1; a++)
		{
			if (b < dim2)
			{
				if (str1[a] == str2[b])
				{
					b++;
				}
				else
				{
					b = b == 0 ? 0 : b--;
				}
			}
			else
			{
				pos = a - b;
				break;
			}
		}
	}

	if (pos != -1)
	{
		std::cout << "\nOccorrenza trovata: ";
		for (int a = 0; a < dim1; a++)
		{
			if (a == pos)
			{
				std::cout << "(";
			}
			std::cout << str1[a];
			if (a == pos + dim2 - 1)
			{
				std::cout << ")";
			}
		}
	}
	else
	{
		std::cout << "\nNessuna occorrenza trovata";
	}

	std::cout << "\n\n";
	return 0;
}
