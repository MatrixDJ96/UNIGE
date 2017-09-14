#include "Stringhe.h"
#include <cmath>

int checkDim(const char* str1)
{
	if (str1 != NULL)
	{
		int dim = 1;
		for (int i = 0; str1[i] != '\0'; i++)
		{
			dim++;
		}
		return dim;
	}
	return -1;
}

char* setStr(const char* str1)
{
	if (str1 != NULL)
	{
		int d = checkDim(str1);
		char* str2 = new char[d];
		for (int i = 0; i < d; i++)
		{
			if (i == d - 1)
			{
				str2[i] = '\0';
			}
			else
			{
				str2[i] = str1[i];
			}
		}
		return str2;
	}
	return NULL;
}

char* insertStr(std::istream& is, bool space)
{
	char* str;
	do {
		str = new char[256];
		is.getline(str, 256, '\n');
	} while (sameWord(str, "") || sameWord(str, " "));
	if (space == true)
	{
		space = false;
		int dim = checkDim(str);
		for (int i = 0; i < dim; i++)
		{
			if (str[i] == ' ')
			{
				space = true;
				dim = i + 1;
				break;
			}
		}
		if (space == true)
		{
			char* new_str = new char[dim];
			for (int i = 0; i < dim; i++)
			{
				if (i == dim - 1)
				{
					new_str[i] = '\0';
				}
				else
				{
					new_str[i] = str[i];
				}
			}
			str = new_str;
		}
	}

	return str;
}

char* intToStr(int integer)
{
	int max = 9;
	int num_char = 2; // caratteri minimi per creazione stringa
	bool neg = false;
	if (integer < 0)
	{
		neg = true;
		integer = -integer;
		num_char++;
	}
	while (integer > max)
	{
		max = max * 10 + 9;
		num_char++;
	}
	char* str = new char[num_char];
	int s = 0; // sottraendo
	for (int i = 0; i < num_char; i++)
	{
		if (i == num_char - 1)
		{
			str[i] = '\0';
		}
		else
		{
			if (i == 0 && neg == true)
			{
				str[i] = '-';
			}
			else
			{
				int d = 1; // divisore
				if (i < num_char - 1)
				{
					d = int(pow(10, num_char - 2 - i));
				}
				str[i] = (integer - s) / d + '0';
				s += (str[i] - '0') * d;
			}
		}
	}
	return str;
}

int strToInt(const char* str)
{
	int integer = -1;
	if (str != NULL)
	{
		int occ = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				occ++;
			}
		}
		if (occ == checkDim(str) - 1 && occ != 0)
		{
			integer = 0;
			for (int i = 0; str[i] != '\0'; i++)
			{
				integer = integer * 10 + str[i] - '0';
			}
		}
	}
	return integer;
}

double strToDouble(const char * str)
{
	double num_double = -1;
	if (str != NULL)
	{
		int occ = 0;
		int point = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',')
			{
				if (str[i] == '.' || str[i] == ',')
				{
					if (point == 0)
					{
						point = 1;
					}
					else
					{
						break;
					}
				}
				occ++;
			}
		}
		if (occ == checkDim(str) - 1 && occ != 0)
		{
			num_double = 0;
			point = 0;
			int after_point = 0;
			for (int i = 0; str[i] != '\0'; i++)
			{
				if (point == 1)
				{
					point = 2;
				}
				if (str[i] == '.' || str[i] == ',')
				{
					point = 1;
				}
				if (point == 0)
				{
					num_double = num_double * 10 + str[i] - '0';
				}
				else if (point == 2)
				{
					after_point++;
					num_double = num_double + (str[i] - '0') / pow(10, after_point);
				}
			}
		}
	}
	return num_double;
}

bool sameWord(const char* str1, const char* str2)
{
	if (str1 != NULL && str2 != NULL)
	{
		int dim1 = checkDim(str1) - 1;
		int dim2 = checkDim(str2) - 1;
		if (dim1 == dim2)
		{
			int occ = 0;
			for (int i = 0; i < dim1; i++)
			{
				if (str1[i] == str2[i])
				{
					occ++;
				}
			}
			if (occ == dim1)
			{
				return true;
			}
		}
	}
	return false;
}
