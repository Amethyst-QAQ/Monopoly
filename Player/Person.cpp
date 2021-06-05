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

}