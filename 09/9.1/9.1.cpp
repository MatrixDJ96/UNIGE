#include <iostream>

int main()
{
	int a, b, c;
	int* pa = &a;
	int* pb = &b;
	int* pc = &c;

	std::cout << "Inserisci 3 numeri interi:\na) ";
	std::cin >> a;
	std::cout << "b) ";
	std::cin >> b;
	std::cout << "c) ";
	std::cin >> c;

	int tmp;
	tmp = *pa;
	*pa = *pc;
	*pc = *pb;
	*pb = tmp;

	std::cout << "\nValori ruotati: " << a << ", " << b << ", " << c << "\n\n";

	return 0;
}
