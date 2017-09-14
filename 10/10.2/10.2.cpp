#include <iostream>

const int max = 256;

int check_dim(char* str1, char* str2)
{
	int dim = 1;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		dim++;
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		dim++;
	}
	return dim;
}

char* set_str(char* str1, char* str2)
{
	int d = check_dim(str1, str2);
	char* str3 = new char[d];
	for (int i = 0; i < d; i++)
	{
		for (int a = 0; str1[a] != '\0'; a++)
		{
			str3[i] = str1[a];
			i++;
		}
		for (int a = 0; str2[a] != '\0'; a++)
		{
			str3[i] = str2[a];
			i++;
		}
	}
	str3[d - 1] = '\0';
	return str3;
}

int main()
{
	char str1[max];
	char str2[max];

	std::cout << "Inserisci una stringa (max 255 char): ";
	std::cin.getline(str1, 256, '\n');

	std::cout << "Inserisci un'altra stringa (max 255 char): ";
	std::cin.getline(str2, 256, '\n');

	char* str3 = set_str(str1, str2);

	std::cout << "\nStringa finale: " << str3 << "\n\n";
	delete[] str3;

	return 0;
}
