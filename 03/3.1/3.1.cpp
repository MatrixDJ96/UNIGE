#include <iostream>

int main()
{
	double a, b, c;
	char d;
	std::cout << "Primo numero: ";
	std::cin >> a;
	std::cout << "Secondo numero: ";
	std::cin >> b;

	std::cout << "Operatore: ";
	std::cin >> d;

	switch (d)
	{
	case '+': c = a + b;
		break;
	case '-': c = a - b;
		break;
	case '*': c = a * b;
		break;
	case '/': c = a / b;
		break;
	default: d = '\0';
		break;
	}

	if (d != '\0')
	{
		std::cout << '\n' << a << " " << d << " " << b << " = " << c << "\n\n";
	}
	else
	{
		std::cout << "\nImpossibile eseguire l'operazione richiesta\n\n";
	}

	return 0;
}
