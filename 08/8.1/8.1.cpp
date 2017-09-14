#include <iostream>
#include <limits>

const int max_char = 32;
const int max_esami = 100;

struct esame {
	char nome[max_char];
	char cognome[max_char];
	int matricola;
	int voto;
};

int inserimento_esame(int &i, esame e[])
{
	if (i >= 100)
	{
		return -1;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // pulizia buffer std::cin

	std::cout << "\nNome studente: ";
	std::cin.getline(e[i].nome, max_char, '\n');
	std::cout << "Cognome studente: ";
	std::cin.getline(e[i].cognome, max_char, '\n');
	std::cout << "Numero matricola: ";
	std::cin >> e[i].matricola;

	do {
		std::cout << "Voto conseguito: ";
		std::cin >> e[i].voto;
		if (e[i].voto < 18 || e[i].voto > 30)
		{
			std::cout << "\nIl voto inserito non è valido. Riprova\n\n";
		}
	} while (e[i].voto < 18 || e[i].voto > 30);

	i++;
	return 0;
}

int media_voti(int i, esame e[])
{

	if (i == 0)
	{
		std::cout << "\nNon posso calcolare la media di 0 esami\n";
		return -1;
	}

	double media = 0.0;
	int somma = 0;
	for (int a = 0; a < i; a++)
	{
		somma += e[a].voto;
	}

	media = double(somma) / i;
	std::cout << "\nLa media dei voti equivale a " << media << '\n';

	return 0;
}

int voto_sup(int i, esame e[])
{
	if (i == 0)
	{
		std::cout << "\nNon posso stampare i miglior voti di 0 esami\n";
		return -1;
	}

	int num_studenti = 0;
	int min_voto = 0;
	std::cout << "\nVoto superiore a? ";
	std::cin >> min_voto;

	for (int a = 0; a < i; a++)
	{
		if (e[a].voto > min_voto)
		{
			num_studenti++;
		}
	}

	std::cout << "\nStudenti con voto superiore a " << min_voto << ": " << num_studenti << '\n';

	return 0;
}

int istogramma(int i, esame e[])
{
	if (i == 0)
	{
		std::cout << "\nNon posso stampare l'istrogramma di 0 esami\n";
		return -1;
	}

	int voto = 18;
	int num_voti = 0;

	do {
		for (int a = 0; a < i; a++)
		{
			if (e[a].voto == voto)
			{
				num_voti++;
			}
		}

		if (num_voti != 0)
		{
			std::cout << '\n' << voto << ": ";
			for (int b = 0; b < num_voti; b++)
			{
				std::cout << "X";
			}
		}
		voto++;
		num_voti = 0;
	} while (voto <= 30);

	std::cout << '\n';

	return 0;
}

int main()
{
	int num_esami = 0;
	esame db_esami[max_esami];
	bool ripeti = true;

	char opzione;
	do {
		std::cout << "Seleziona un opzione:\n1) Inserisci esame\n2) Stampa media voti\n3) Stampa numero studenti con voto maggiore di x\n4) Stampa istrogramma voti\n5) Esci dal programma\n\n(1-5) -> ";
		std::cin >> opzione;
		if (!(opzione >= '1' && opzione <= '5'))
		{
			std::cout << "\nOpzione non valida. Riprova\n";
		}

		if (opzione == '1')
		{
			inserimento_esame(num_esami, db_esami);
		}
		else if (opzione == '2')
		{
			media_voti(num_esami, db_esami);
		}
		else if (opzione == '3')
		{
			voto_sup(num_esami, db_esami);
		}
		else if (opzione == '4')
		{
			istogramma(num_esami, db_esami);
		}
		else if (opzione == '5')
		{
			ripeti = false;
		}

		std::cout << '\n';
	} while (ripeti == true);

	return 0;
}
