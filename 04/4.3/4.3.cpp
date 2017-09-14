#include <iostream>

const int nmax = 100;

int main()
{
	int nums[nmax];
	int pos = -1;
	int n = 0;

	std::cout << "Inserisci " << nmax << " numeri interi positivi\nPer terminare l'inserimento digita 0\n\n";

	for (int i = 0; i < nmax; i++)
	{
		std::cout << i + 1 << ": ";
		std::cin >> n;
		if (n > 0)
		{
			nums[i] = n;
		}
		else
		{
			if (i != 0)
			{
				pos = i;
			}
			break;
		}
	}

	std::cout << "\nNumeri pari inseriti: ";
	if (pos != -1)
	{
		for (int i = 0; i < pos; i++)
		{
			if (nums[i] % 2 == 0)
			{
				std::cout << nums[i];
				if (i + 1 != pos)
				{
					std::cout << ", ";
				}
			}
		}
	}
	else
	{
		std::cout << "nessuno";
	}

	std::cout << "\n\n";
	return 0;
}
