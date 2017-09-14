#include <stdlib.h>

#include "Poligono2D.h"

int main()
{
	int vertici;
	do {
		std::cout << "Inserire il numero di vertici di un poligono: ";
		std::cin >> vertici;
		if (vertici < 1)
		{
			std::cout << "\nIl numero di vertici deve essere un numero > di zero\n\n";
		}
	} while (vertici < 1);

	Poligono2D poligono(vertici);
	std::cout << "\nInserisci le coordinate dei vertici del poligono\n";
	std::cin >> poligono;

	#if defined(__linux__)
		system("clear");
	#elif defined(_WIN32)
		system("cls");
	#endif

	std::cout << "Il perimetro del poligono formato dai seguenti " << poligono.getNumVertici() << " vertici misura " << poligono.getPerimetro() << '\n';
	std::cout << poligono << "\n\n";

	return 0;
}
