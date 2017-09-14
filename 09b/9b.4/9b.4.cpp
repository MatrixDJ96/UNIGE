#include <iostream>

const int dim = 256;
int dim1, dim2;

int dim_size(char c[])
{
	int b = 1;
	for (int a = 0; c[a] != '\0'; a++)
	{
		b++;
	}
	return b;
}

int str_check(char* str1, char* str2)
{
	dim1 = dim_size(str1) - 1; // metto il -1 per escludere il char '\0'
	dim2 = dim_size(str2) - 1; // idem

	int occ = 0; // numero occorrenze
	int pos = -1; // posizione prima occorrenza

	if (dim1 >= dim2)
	{
		int b = 0; // posizione stringa 2
		for (int a = 0; a < dim1; a++)
		{
			if (b < dim2)
			{
				if (str1[a] == str2[b])
				{
					occ++;
					if (pos == -1)
					{
						pos = a; // imposto posizione della prima occorrenza
					}
					b++;
				}
				else
				{
					occ = 0;
					pos = -1;
					b = 0;
				}
			}
			else
			{
				a = dim1;
			}
		}
	}
	if (pos == -1)
	{
		return NULL; // non posso fare return -1 per consegna
	}
	else
	{
		return pos + 1; // per essere coerente con il main
	}
}

int main()
{
	char str1[dim];
	char str2[dim];

	std::cout << "Inserisci una stringa: ";
	std::cin.getline(str1, dim, '\n');

	std::cout << "Inserisci un'altra stringa: ";
	std::cin.getline(str2, dim, '\n');

	int pos = str_check(str1, str2) - 1; // posizione prima occorrenza

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
