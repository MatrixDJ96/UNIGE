#include <iostream>
#include <math.h>

int num_invertito(char s[])
{
	int nchar = 0;
	int npow = 0;
	int num = 0;
	if (s[0] == '-')
	{
		std::cout << "\nNon hai inserito un numero positivo\n\n";
		return -1;
	}
	for (int k = 0; s[k] != '\0'; k++)
	{
		if (!(s[k] >= '0' && s[k] <= '9'))
		{
			nchar++;
		}
		else
		{
			num += (s[k] - '0') * int(pow(10, npow));
			npow++;
		}
	}

	if (nchar != 0)
	{
		std::cout << "\nNon hai inserito un numero\n\n";
		return -1;
	}

	if (num == 1)
	{
		std::cout << "\nIl numero che hai inserito ha una sola cifra\n\n";
		return -1;
	}

	return num;
}

int main()
{
	char n1[32];

	std::cout << "Inserisci un numero positivo: ";
	std::cin >> n1;
	int n2 = num_invertito(n1);
	if (n2 != -1)
	{
		std::cout << "\nLe cifre invertite sono " << n2 << "\n\n";
	}

	return 0;
}
