#include <iostream>

const int max = 100;

int conta(char s[], int a[], int &n)
{
	n = 0;

	for (int i = 0; i < max; i++)
	{
		a[i] = 0;
	}

	bool isPrevNum = false;
	int ia = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (isPrevNum == false)
			{
				isPrevNum = true;
				a[ia] = s[i] - '0';
				ia++;
			}
			else
			{
				a[ia - 1] = a[ia - 1] * 10 + (s[i] - '0');
			}
		}
		else
		{
			isPrevNum = false;
		}
	}

	return ia;
}

int main()
{
	char s[max];
	int a[max];
	int n;
	std::cout << "Scrivi una frase (max " << max << " caratteri): ";
	std::cin.getline(s, max, '\n');
	n = conta(s, a, n);
	std::cout << "\nNumeri trovati: " << n << "\n\n";

	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ": " << a[i] << '\n';
	}

	std::cout << '\n';
	return 0;
}
