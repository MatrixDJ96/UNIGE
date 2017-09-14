#include <iostream>

int error(int a, int b, int c, int d)
{
	int err = 0;
	if (a == c)
	{
		std::cout << "Non puoi inserire due vertici che abbiamo la stessa x" << '\n';
		err = 1;
	}
	if (b == d)
	{
		std::cout << "Non puoi inserire due vertici che abbiamo la stessa y" << '\n';
		err = 1;
	}
	return err;
}

int main()
{
	int x, y;
	int a, b, c, d;

	std::cout << "Scrivi le coordinate di un punto P(x, y): ";
	std::cin >> x >> y;

	std::cout << "Scrivi le coordinate di un vertice (a, b) di un rettangolo: ";
	std::cin >> a >> b;

	std::cout << "Scrivi le coordinate di un altro vertice (c, d) di un rettangolo: ";
	std::cin >> c >> d;

	int tmp = 0;
	if (a > c)
	{
		tmp = c;
		c = a;
		a = tmp;
	}

	if (b > d)
	{
		tmp = d;
		d = b;
		b = tmp;
	}

	if (error(a, b, c, d) == 1)
	{
		return 0;
	}

	if (a < x && c > x && b < y && d > y)
	{
		std::cout << "\nIl punto P(" << x << ", " << y << ") e' interno al rettangolo\n\n";
	}
	else
	{
		std::cout << "\nIl punto P(" << x << ", " << y << ") e' esterno al rettangolo\n\n";
	}

	return 0;
}
