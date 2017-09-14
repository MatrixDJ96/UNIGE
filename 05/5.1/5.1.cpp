#include <iostream>
#include <math.h>

double distanza(int a, int b, int c, int d)
{
	return sqrt(pow(a - c, 2) + pow(b - d, 2));
}

int main()
{
	int a, b;
	std::cout << "Inserisci le coordinate di un punto A (a, b): ";
	std::cin >> a >> b;

	int c, d;
	std::cout << "Inserisci le coordinate di un punto B (c, d): ";
	std::cin >> c >> d;

	std::cout << "\nLa distanza fra A e B vale " << distanza(a, b, c, d) << "\n\n";
	return 0;
}
