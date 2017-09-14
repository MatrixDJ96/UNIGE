#include <iostream>

int conta(char string[], int voc[])
{
	for (int a = 0; string[a] != '\0'; a++)
	{
		if (string[a] == 'a')
		{
			voc[0]++;
		}
		else if (string[a] == 'e')
		{
			voc[1]++;
		}
		else if (string[a] == 'i')
		{
			voc[2]++;
		}
		else if (string[a] == 'o')
		{
			voc[3]++;
		}
		else if (string[a] == 'u')
		{
			voc[4]++;
		}
	}

	return voc[0] + voc[1] + voc[2] + voc[3] + voc[4];
}

int main()
{
	char s[256];
	int a[5] = { 0,0,0,0,0 };

	std::cout << "Scrivi una frase: ";
	std::cin.getline(s, 256, '\n');

	int nv = conta(s, a);

	std::cout << "\nConta a: " << a[0] << '\n';
	std::cout << "Conta e: " << a[1] << '\n';
	std::cout << "Conta i: " << a[2] << '\n';
	std::cout << "Conta o: " << a[3] << '\n';
	std::cout << "Conta u: " << a[4] << '\n';


	std::cout << "\nIn totale hai inserito " << nv;
	if (nv == 1)
	{
		std::cout << " vocale\n\n";
	}
	else
	{
		std::cout << " vocali\n\n";
	}

	return 0;
}
