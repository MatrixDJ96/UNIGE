#include "Punto2D.h"

int main()
{
	Punto2D puntoA, puntoB;

	std::cout << "Inserisci coordinate del punto A(x, y): ";
	std::cin >> puntoA;
	std::cout << "Inserisci coordinate del punto B(x, y): ";
	std::cin >> puntoB;

	std::cout << "\nPunto A: " << puntoA << "\nPunto B: " << puntoB;
	std::cout << "\n\nSomma fra A e B: " << puntoA + puntoB;
	std::cout << "\nDifferenza fra A e B: " << puntoA - puntoB;
	std::cout << "\nDistanza fra A e B: " << puntoA.getDistanzaFrom(puntoB) << "\n\n";

	return 0;
}
