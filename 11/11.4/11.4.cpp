#include <iostream>

void hanoi(char palo_1, char palo_2, char palo_3, int dischi)
{
	if (dischi == 1)
	{
		std::cout << "Posto il disco n." << dischi << " dal palo " << palo_1 << " al palo " << palo_2 << '\n';
	}
	else
	{
		hanoi(palo_1, palo_3, palo_2, dischi - 1);
		std::cout << "Posto il disco n." << dischi << " dal palo " << palo_1 << " al palo " << palo_2 << '\n';
		hanoi(palo_3, palo_2, palo_1, dischi - 1);
	}
}

int main()
{
	hanoi('A', 'C', 'B', 3);

	std::cout << '\n';

	return 0;
}
