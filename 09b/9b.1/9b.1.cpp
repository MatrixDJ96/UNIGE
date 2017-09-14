#include <iostream>

void ruota(int* pa, int* pb, int* pc)
{
	int tmp;
	tmp = *pa;
	*pa = *pc;
	*pc = *pb;
	*pb = tmp;
}

int main()
{
	int a, b, c;

	std::cout << "Inserisci 3 numeri interi:\na) ";
	std::cin >> a;
	std::cout << "b) ";
	std::cin >> b;
	std::cout << "c) ";
	std::cin >> c;

	ruota(&a, &b, &c);

	std::cout << "\nValori ruotati: " << a << ", " << b << ", " << c << "\n\n";

	return 0;
}
