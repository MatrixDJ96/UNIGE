#include<iostream>

void swap(int& ra, int& rb)
{
	int tmp;
	tmp = ra;
	ra = rb;
	rb = tmp;
}

int main()
{
	int a, b;

	std::cout << "Inserisci un numero intero: ";
	std::cin >> a;
	std::cout << "Inserisci un altro numero intero: ";
	std::cin >> b;

	swap(a, b);

	std::cout << "\nNumeri invertiti: " << a << ", " << b << "\n\n";

	return 0;
}
