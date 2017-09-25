#include <iostream>

const int max = 256;

int confronto(char a[], char b[])
{
	int n1 = 0;
	int n2 = 0;
	for (int c = 0; c < max; c++)
	{
		if (a[c] == '\0') break;
		else n1++;
	}

	for (int c = 0; c < max; c++)
	{
		if (b[c] == '\0') break;
		else n2++;
	}

	char c[max];
	for (int i = 0; i <= n1; i++)
	{
		c[i] = b[i];
	}

	if (n1 != n2)
	{
		return 0;
	}
	else
	{
		for (int i1 = 0; i1 < n1; i1++)
		{
			for (int i2 = 0; i2 < n1; i2++)
			{
				if (a[i1] == c[i2])
				{
					c[i2] = ' ';
					break;
				}
				else
				{
					if (i2 == n1 - 1) return 0;
				}
			}
		}
		return 1;
	}

}

int main()
{
	char parola1[max];
	char parola2[max];
	int ana;

	std::cout << "Scrivi due parole:\n1: ";
	std::cin >> parola1;
	std::cout << "2: ";
	std::cin >> parola2;

	ana = confronto(parola1, parola2);

	if (ana == 0)  std::cout << "\nNon sono ";
	else std::cout << "\nSono ";
	std::cout << "anagrammi\n\n";

	return 0;
}
