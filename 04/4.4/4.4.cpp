#include <iostream>

const int nmax = 100;

int main()
{
	std::cout << "Inserisci alcuni valori reali (max 100)\nPer terminare l'inserimento digita 0\n\n";

	double num[nmax];
	double max = 0;
	double min = 0;
	int err = 0;

	for (int n = 0; n < nmax; n++)
	{
		std::cout << n + 1 << ": ";
		std::cin >> num[n];
		if (num[n] == 0)
		{
			if (n == 0)
			{
				err = 1;
			}
			break;
		}
		else
		{
			if (min == 0)
			{
				min = num[n];
			}
			else
			{
				if (num[n] < min)
				{
					min = num[n];
				}
			}
			if (max == 0)
			{
				max = num[n];
			}
			else
			{
				if (num[n] > max)
				{
					max = num[n];
				}
			}
		}
	}


	if (err == 0)
	{
		std::cout.precision(10);
		std::cout << "\nNumero max: " << max;
		std::cout << "\nNumero min: " << min << "\n\n";
	}
	else
	{
		std::cout << "\nNessun numero inserito\n\n";
	}
	return 0;
}
