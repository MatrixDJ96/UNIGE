#include <iostream>

int main()
{
	long int tempo;
	long int settimane;
	long int ssettimane;
	long int giorni;
	long int sgiorni;
	long int ore;
	long int sore;
	long int minuti;
	long int sminuti;
	long int secondi;

	std::cout << "Scrivi un tempo in secondi: ";
	std::cin >> tempo;

	if (tempo < 60)
	{
		std::cout << '\n';
		return 0;
	}

	settimane = tempo / 60 / 60 / 24 / 7;
	ssettimane = settimane * 60 * 60 * 24 * 7;

	giorni = (tempo - ssettimane) / 60 / 60 / 24;
	sgiorni = giorni * 60 * 60 * 24;

	ore = (tempo - ssettimane - sgiorni) / 60 / 60;
	sore = ore * 60 * 60;

	minuti = (tempo - ssettimane - sgiorni - sore) / 60;
	sminuti = minuti * 60;

	secondi = (tempo - ssettimane - sgiorni - sore - sminuti);

	std::cout << '\n' << tempo << " secondi equivalgono a: " <<
		settimane << " settimane, " <<
		giorni << " giorni, " <<
		ore << " ore, " <<
		minuti << " minuti e " <<
		secondi << " secondi\n\n";

	return 0;
}
