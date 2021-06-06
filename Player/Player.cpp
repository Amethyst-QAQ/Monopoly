#include "Player.h"

void Player::buyCountry()
{
	countryNum++;
}

void Player::buyPowerStation()
{
	powerStationNum++;
}

void Player::setMoney(int _money)
{
	if (_money < 0)
		broke();
	else
		money = _money;
}

void Player::broke()
{
	std::string mainText = "You don't have enough money.Do you want to pledge one of your countries or a power station£¿";
	std::string serveText = "broke";
	std::vector<std::string> operation = { "One of my countries.", "A power station." };

	Menu menu(mainText, operation, serveText);
	int n = menu.exec();
	//Î´Íê´ýÐø ¡­ ¡­
}