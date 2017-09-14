#include<iostream>

void swap1(int& ra, int& rb)
{
	int tmp;
	tmp = ra;
	ra = rb;
	rb = tmp;
}

void swap2(int* pa, int* pb)
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int main()
{
	int a, b, c;

	std::cout << "Inserisci un numero intero: ";
	std::cin >> a;
	std::cout << "Inserisci un altro numero intero: ";
	std::cin >> b;

	do {
		std::cout << "\nVuoi usare SWAP1 o SWAP2? (1/2)\n-> ";
		std::cin >> c;

		if (c == 1)
		{
			swap1(a, b);
		}
		else if (c == 2)
		{
			swap2(&a, &b);
		}

		if (c == 1 || c == 2)
		{
			std::cout << "\nSWAP2: Numeri invertiti: " << a << ", " << b << "\n\n";
		}
		else
		{
			std::cout << "\nRisposta non valida.\n";
		}
	} while (c != 1 && c != 2);

	return 0;
}
