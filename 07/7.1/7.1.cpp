#include <iostream>

const int max = 256;

int sostituisci(char s[], char a, char b)
{
	int n = 0;
	for (int c = 0; c < max; c++)
	{
		if (s[c] != '\0')
		{
			if (s[c] == a)
			{
				s[c] = b;
				n++;
			}
		}
		else c = max;
	}

	return n;
}

int main()
{
	char s[max];
	char a;
	char b;

	std::cout << "Scrivi una frase: ";
	std::cin.getline(s, max, '\n');
	std::cout << "Trova il carattere -> ";
	std::cin >> a;
	std::cout << "Sostituisci con -> ";
	std::cin >> b;

	int sost = sostituisci(s, a, b);

	std::cout << "\nRisultato: " << s;

	std::cout << "\n\nHo eseguito " << sost;
	if (sost == 1)
	{
		std::cout << " sostituzione\n\n";
	}
	else
	{
		std::cout << " sostituzioni\n\n";
	}

	return 0;
}
