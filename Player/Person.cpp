#include "Person.h"

void Person::buyCountry()
{
	countryNum++;
}

void Person::buyPowerStation()
{
	powerStationNum++;
}

void Person::setMoney(int _money)
{
	if (_money < 0)
		broke();
	else
		money = _money;
}

void Person::broke()
{
	std::string mainText = "You don't have enough money.Do you want to pledge one of your countries or a power station£¿";
	std::string serveText = "broke";
	std::vector<std::string> operation = { "One of my countries.", "A power station." };

	Menu menu(mainText, operation, serveText);
	int n = menu.exec();
	//Î´Íê´ýÐø ¡­ ¡­
}