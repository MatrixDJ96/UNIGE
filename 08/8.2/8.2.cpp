#include <iostream>
#include <limits>

const int max_char = 256;
const int max_appartamenti = 100;

struct appartamento {
	int codice;
	int numero_vani;
	int mq;
	double prezzo;
	char via[max_char];
	char comune[max_char];
};

int inserimento_appartamento(int &i, appartamento a[])
{
	if (i >= 100)
	{
		return -1;
	}

	std::cout << "\nCodice appartamento: ";
	std::cin >> a[i].codice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // pulizia buffer std::cin

	std::cout << "Via appartamento: ";
	std::cin.getline(a[i].via, max_char, '\n');
	std::cout << "Comune appartamento: ";
	std::cin.getline(a[i].comune, max_char, '\n');

	bool ripeti = false;
	do {
		std::cout << "Numero vani appartamento: ";
		std::cin >> a[i].numero_vani;
		if (a[i].numero_vani <= 0)
		{
			std::cout << "\nNumero vani non valido. Riprova\n\n";
			ripeti = true;
		}
		else
		{
			ripeti = false;
		}
	} while (ripeti == true);

	do {
		std::cout << "Metri quadrati appartamento: ";
		std::cin >> a[i].mq;
		if (a[i].mq <= 0)
		{
			std::cout << "\nMetri quadrati non validi. Riprova\n\n";
			ripeti = true;
		}
		else
		{
			ripeti = false;
		}
	} while (ripeti == true);

	do {
		std::cout << "Prezzo appartamento: ";
		std::cin >> a[i].prezzo;
		if (a[i].prezzo <= 0)
		{
			std::cout << "\nPrezzo non valido. Riprova\n\n";
			ripeti = true;
		}
		else
		{
			ripeti = false;
		}
	} while (ripeti == true);

	i++;
	return 0;
}

int info_vani(int i, appartamento a[])
{
	if (i == 0)
	{
		std::cout << "\nNon posso elaborare informazioni su 0 appartamenti\n";
		return -1;
	}

	int num_app = 0;
	int vani = 0;
	std::cout << "\nNumero vani? ";
	std::cin >> vani;

	for (int b = 0; b < i; b++)
	{
		if (a[b].numero_vani == vani)
		{
			num_app++;
			std::cout << "\nCodice appartamento: " << a[b].codice;
			std::cout << "\nVia appartamento: " << a[b].via;
			std::cout << "\nComune appartamento: " << a[b].comune;
			std::cout << "\nMetri quadrati appartamento: " << a[b].mq;
			std::cout << "\nPrezzo appartamento: " << a[b].prezzo;
			std::cout << "\nNumero vani appartamento: " << a[b].numero_vani << '\n';
		}
	}

	if (num_app == 0)
	{
		std::cout << "\nNon ci sono appartamenti registrati con il numero di vani indicato\n";
	}

	return 0;
}

int prezzi_appartamenti(int i, appartamento a[])
{
	if (i == 0)
	{
		std::cout << "\nNon posso calcolare la media di 0 esami\n";
		return -1;
	}

	double min = 0.0;
	double max = 0.0;
	double somma = 0.0;
	double media = 0.0;

	for (int b = 0; b < i; b++)
	{
		somma += a[b].prezzo;
		if (min == 0.0 || a[b].prezzo < min)
		{
			min = a[b].prezzo;
		}
		if (max == 0.0 || a[b].prezzo > max)
		{
			max = a[b].prezzo;
		}
	}

	media = somma / i;

	std::cout << "\nIl prezzo minimo vale " << min;
	std::cout << "\nIl prezzo massimo vale " << max;
	std::cout << "\nLa media dei prezzi vale " << media << "\n\n";

	return 0;
}

int info_mq(int i, appartamento a[])
{
	if (i == 0)
	{
		std::cout << "\nNon posso elaborare informazioni su 0 appartamenti\n";
		return -1;
	}

	int num_app = 0;
	int min_mq = 0;
	int max_mq = 0;
	std::cout << "\nMetri quadrati compresi fra? (es: 10 50)\n-> ";
	std::cin >> min_mq >> max_mq;

	if (min_mq > max_mq)
	{
		int *tmp = new int;
		*tmp = min_mq;
		min_mq = max_mq;
		max_mq = *tmp;
		delete tmp;
	}

	for (int b = 0; b < i; b++)
	{
		if (a[b].mq > min_mq && a[b].mq < max_mq)
		{
			num_app++;
		}
	}

	std::cout << "\nAppartamenti con m.q. compresi fra " << min_mq << " e " << max_mq << ": " << num_app << '\n';

	return 0;
}

int info_prezzo(int i, appartamento a[])
{
	if (i == 0)
	{
		std::cout << "\nNon posso elaborare informazioni su 0 appartamenti\n";
		return -1;
	}

	int num_app = 0;
	int min_prezzo = 0;
	int max_prezzo = 0;
	std::cout << "\nPrezzo compreso fra? (es: 100 300)\n-> ";
	std::cin >> min_prezzo >> max_prezzo;

	if (min_prezzo > max_prezzo)
	{
		int *tmp = new int;
		*tmp = min_prezzo;
		min_prezzo = max_prezzo;
		max_prezzo = *tmp;
		delete tmp;
	}

	for (int b = 0; b < i; b++)
	{
		if (a[b].prezzo > min_prezzo && a[b].prezzo < max_prezzo)
		{
			num_app++;
			std::cout << "\nCodice appartamento: " << a[b].codice;
			std::cout << "\nVia appartamento: " << a[b].via;
			std::cout << "\nComune appartamento: " << a[b].comune;
			std::cout << "\nMetri quadrati appartamento: " << a[b].mq << '\n';
		}
	}

	if (num_app == 0)
	{
		std::cout << "\nNon ci sono appartamenti registrati con il prezzo indicato\n";
	}

	return 0;
}

int istogramma(int i, appartamento a[])
{
	if (i == 0)
	{
		std::cout << "\nNon posso stampare l'istrogramma di 0 appartamenti\n";
		return -1;
	}

	int vani = 1;
	int num_app = 0;

	int max_vani = 0;
	for (int b = 0; b < i; b++)
	{
		if (max_vani == 0 || max_vani < a[b].numero_vani)
		{
			max_vani = a[b].numero_vani;
		}
	}

	do {
		for (int b = 0; b < i; b++)
		{
			if (a[b].numero_vani == vani)
			{
				num_app++;
			}
		}

		if (num_app != 0)
		{
			std::cout << '\n' << vani << ": ";
			for (int b = 0; b < num_app; b++)
			{
				std::cout << "X";
			}
		}
		vani++;
		num_app = 0;
	} while (vani <= max_vani);

	std::cout << '\n';

	return 0;
}

int main()
{
	int num_appartamenti = 0;
	appartamento db_appartamenti[max_appartamenti];
	bool ripeti = true;

	char opzione;
	do {
		std::cout << "Seleziona un opzione:\n1) Inserisci dati appartamento\n2) Stampa massimo, minimo e media prezzi appartamenti\n3) Stampa numero appartamenti con m.q. compresi fra x e y\n4) Stampa istogramma vani\n5) Stampa informazioni su appartamenti con x vani\n6) Stampa numero appartamenti con prezzo compreso fra x e y\n7) Esci dal programma\n\n(1-7) -> ";
		std::cin >> opzione;
		if (!(opzione >= '1' && opzione <= '7'))
		{
			std::cout << "\nOpzione non valida. Riprova\n";
		}

		if (opzione == '1')
		{
			inserimento_appartamento(num_appartamenti, db_appartamenti);
		}
		else if (opzione == '2')
		{
			prezzi_appartamenti(num_appartamenti, db_appartamenti);
		}
		else if (opzione == '3')
		{
			info_mq(num_appartamenti, db_appartamenti);
		}
		else if (opzione == '4')
		{
			istogramma(num_appartamenti, db_appartamenti);
		}
		else if (opzione == '5')
		{
			info_vani(num_appartamenti, db_appartamenti);
		}
		else if (opzione == '6')
		{
			info_prezzo(num_appartamenti, db_appartamenti);
		}
		else if (opzione == '7')
		{
			ripeti = false;
		}

		std::cout << '\n';
	} while (ripeti == true);

	return 0;
}
