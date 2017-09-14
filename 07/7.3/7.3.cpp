#include <iostream>

const int max = 256;

int rimuovi(char s[], char a)
{
	char ns[max];
	int nb = 0;
	int rim = 0;
	for (int b = 0; s[b] != '\0'; b++)
	{
		if (s[b] != a)
		{
			ns[nb] = s[b];
			nb++;
		}
		else
		{
			rim++;
		}
	}
	ns[nb] = '\0';

	for (int b = 0; b <= nb; b++)
	{
		s[b] = ns[b];
	}

	return rim;
}

int main()
{
	char s[max];
	char a;

	std::cout << "Scrivi una frase: ";
	std::cin.getline(s, max, '\n');
	std::cout << "Inserisci un carattere da rimuovere: ";
	std::cin >> a;

	int rim = rimuovi(s, a);

	std::cout << "\nRisultato: " << s;

	std::cout << "\n\nHo rimosso " << rim;
	if (rim == 1)
	{
		std::cout << " carattere\n\n";
	}
	else {
		std::cout << " caratteri\n\n";
	}

	return 0;
}
