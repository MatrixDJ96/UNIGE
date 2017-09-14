#include <iostream>

void mcd(int a, int b)
{
	int r = 0;
	if (b == 0)
	{
		std::cout << "\nL'MCD vale " << a << "\n\n";
	}
	else
	{
		r = a % b;
		if (r == 0)
		{
			std::cout << "\nL'MCD vale " << b << "\n\n";
		}
		else
		{
			mcd(b, r);
		}
	}
}

int main()
{
	int a, b;
	std::cout << "Inserisci 2 numeri a e b:\n\na: ";
	std::cin >> a;
	std::cout << "b: ";
	std::cin >> b;
	mcd(a, b);

	return 0;
}
