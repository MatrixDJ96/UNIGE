#include <iostream>
#include <cmath>
#include <std::string>

int main()
{
	int giorno;
	int giorno2;
	int mese;
	int mese2;
	int anno;
	int anno2;

	int bisestile = 0;
	int bisestile2 = 0;
	int febbraio = 28;
	int giorni = 0;
	int giorni2 = 0;
	int mesi = 0;
	int anni = 0;

	int err = 0;

	std::cout << "Scrivi la data di oggi (gg mm aaaa): ";
	std::cin >> giorno >> mese >> anno;
	std::cout << "Scrivi la tua data di nascita (gg mm aaaa): ";
	std::cin >> giorno2 >> mese2 >> anno2;

	if (anno % 100 == 0)
	{
		if (anno % 400 == 0)
		{
			bisestile = 1;
		}
	}
	else if (anno % 4 == 0)
	{
		bisestile = 1;
	}

	if (anno2 % 100 == 0)
	{
		if (anno2 % 400 == 0)
		{
			bisestile2 = 1;
		}
	}
	else if (anno2 % 4 == 0)
	{
		bisestile2 = 1;
	}

	if (bisestile2 == 1)
	{
		febbraio = 29;
	}

	if (anno2 > anno)
	{
		err = 2;
	}
	else if (anno2 == anno)
	{
		if (mese2 > mese)
		{
			err = 2;
		}
		else if (mese2 == mese)
		{
			if (giorno2 > giorno)
			{
				err = 2;
			}
		}
	}

	if (mese > 12 || mese2 > 12)
	{
		err = 1;
	}
	if (giorno > 31 || giorno2 > 31)
	{
		err = 1;
	}
	if (giorno > 30 && (mese == 4 || mese == 6 || mese == 9 || mese == 11))
	{
		err = 1;
	}
	if (giorno == 29 && mese == 2)
	{
		if (bisestile == 0)
		{
			err = 1;
		}
	}
		
	if (giorno2 > 30 && (mese2 == 4 || mese2 == 6 || mese2 == 9 || mese2 == 11))
	{
		err = 1;
	}
	if (giorno2 == 29 && mese2 == 2)
	{
		if (bisestile2 == 0)
		{
			err = 1;
		}
	}

	if (err == 1)
	{
		std::cout << "\nCombinazione date non esistenti\n\n";
		return 0;
	}
	else if (err == 2)
	{
		std::cout << "\nSalve viaggiatore del tempo!\n";
		giorni = giorno;
		giorno = giorno2;
		giorno2 = giorni;
		giorni = 0;
		mesi = mese;
		mese = mese2;
		mese2 = mesi;
		mesi = 0;
		anni = anno;
		anno = anno2;
		anno2 = anni;
		anni = 0;
	}

	if (anno2 == anno)
	{
		if (mese2 == mese)
			giorni = giorno - giorno2;
		else
		{
			if (mese2 == 4 || mese2 == 6 || mese2 == 9 || mese2 == 11)
				giorni = 30 - giorno2;
			else if (mese2 == 2)
				giorni = febbraio - giorno2;
			else
				giorni = 31 - giorno2;
		}
	}
	else
	{
		if (mese2 == 4 || mese2 == 6 || mese2 == 9 || mese2 == 11)
			giorni = 30 - giorno2;
		else if (mese2 == 2)
			giorni = febbraio - giorno2;
		else
			giorni = 31 - giorno2;
	}

	giorni2 = giorni;

	int mese3 = mese2;
	int anno3 = anno2;

	for (anno3; anno3 <= anno; anno3++)
	{
		febbraio = 28;
		bisestile2 = 0;

		if (anno3 % 100 == 0)
		{
			if (anno3 % 400 == 0)
			{
				bisestile2 = 1;
			}
		}	
		else if (anno3 % 4 == 0)
		{
			bisestile2 = 1;

		}
		if (bisestile2 == 1)
		{
			febbraio = 29;
		}
		for (mese3; mese3 < 12; mese3++)
		{
			if (anno3 == anno)
			{
				if (mese3 + 1 == mese)
				{
					giorni = giorni + giorno;
					giorni2 = giorni2 + giorno;
					break;
				}
				else if (mese3 == mese)
				{
					break;
				}
			}
			switch (mese3 + 1)
			{
			case 1:
				giorni = giorni + 31;
				break;
			case 2:
				giorni = giorni + febbraio;
				break;
			case 3:
				giorni = giorni + 31;
				break;
			case 4:
				giorni = giorni + 30;
				break;
			case 5:
				giorni = giorni + 31;
				break;
			case 6:
				giorni = giorni + 30;
				break;
			case 7:
				giorni = giorni + 31;
				break;
			case 8:
				giorni = giorni + 31;
				break;
			case 9:
				giorni = giorni + 30;
				break;
			case 10:
				giorni = giorni + 31;
				break;
			case 11:
				giorni = giorni + 30;
				break;
			case 12:
				giorni = giorni + 31;
				break;
			}
		}
		mese3 = 0;
	}

	anni = anno - anno2;
	if (mese2 > mese)
	{
		anni--;
	}
	
	mesi = mese - mese2;
	if (giorno2 > giorno)
	{
		mesi--;
	}
	if (mesi < 0)
	{
		mesi = 12 + mesi;
		if (mese2 <= mese)
		{
			anni--;
		}
	}
	if (anni < 0)
	{
		anni = 0;
	}
	febbraio = 28;
	if (bisestile2 == 1)
	{
		febbraio = 29;
	}
	if (giorni2 == 30 && (mese2 == 4 || mese2 == 6 || mese2 == 9 || mese2 == 11))
	{
		giorni2 = 0;
	}
	else if (giorni2 > 30 && (mese2 == 4 || mese2 == 6 || mese2 == 9 || mese2 == 11))
	{
		giorni2 = giorni2 - 30;
	}
	else if ((giorni2 == 28 || giorni2 == 29) && mese2 == 2)
	{
		giorni2 = 0;
	}
	else if (giorni2 > febbraio && mese2 == 2)
	{
		giorni2 = giorni2 - febbraio;
	}
	else if (giorni2 == 31 && (mese2 == 1 || mese2 == 3 || mese2 == 5 || mese2 == 7 || mese2 == 8 || mese2 == 10 || mese2 == 12))
	{
		giorni2 = 0;
	}
	else if (giorni2 > 31 && (mese2 == 1 || mese2 == 3 || mese2 == 5 || mese2 == 7 || mese2 == 8 || mese2 == 10 || mese2 == 12))
	{
		giorni2 = giorni2 - 31;
	}
	
	std::string temp01 = "\nHai ";
	std::string temp02 = "Oppure hai ";
	std::string ann01 = " anni, ";
	std::string mes01 = " mesi e ";
	std::string giorn01 = " giorni\n";
	std::string giorn02 = giorn01;
	
	if (anni == 1)
	{
		ann01 = " anno, ";
	}
	if (mesi == 1)
	{
		mes01 = " mese e ";
	}
	if (giorni == 1)
	{
		giorn01 = " giorno\n";
	}
	if (giorni2 == 1)
	{
		giorn02 = " giorno\n";
	}
	if (err == 2)
	{
		temp01 = "\nNascerai fra ";
		temp02 = "Oppure nascerai fra ";
	}

	if (giorno == giorno2 && mese == mese2)
	{
		if (anno == anno2)
		{
			std::cout << "\nSei nato oggi!\n\n";
			return 0;
		}
		else
		{
			if (err != 2)
				std::cout << "\nBuon compleanno!!!\n";
		}
	}

	if (anni >= 100 && err != 2)
	{
		std::cout << "\nChe vita longeva!\n";
	}
	if (anni == 0)
	{
		std::cout << temp01 << mesi << mes01 << giorni2 << giorn02;
	}
	else
	{
		std::cout << temp01 << anni << ann01 << mesi << mes01 << giorni2 << giorn02;
	}

	if (giorni != giorni2)
		std::cout << temp02 << std::abs(giorni) << giorn01;

	std::cout << '\n';
	return 0;
}
