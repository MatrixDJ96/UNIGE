#include "ComparaPrezzi.h"

int main()
{
	double prezzi[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
	
	ComparaPrezzi pr(10, 5, prezzi);
	std::cin >> pr;
	
	double max;
	double min = pr.calcolaPrezzoMinMax(max);
	
	std::cout << "\nIl prezzo minimo vale " << min;
	std::cout << "\nIl prezzo massimo vale " << max << "\n\n";
	
	return 0;
}
