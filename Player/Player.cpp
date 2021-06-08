#include "Player.h"

using namespace std;

void Player::setMoney(int _money)
{
	if (_money < 0)
		broke();
	else
		money = _money;
}

void Player::buyStock(int sum, float price)
{
	price = price * sum;
	if (money >= price)
	{
		stockNum += sum;
		money -= price;
	}
	else broke();
}

void Player::sellStock(int sum, float price)
{
	stockNum -= sum;		//���˳ֹ�������
	money += (sum * price);	//����Ǯ������
}

void Player::show()
{
	std::string mainText;
	std::string serveText;
	
	//δ����� �� ��
}

void Player::broke()
{
	std::string mainText = "You don't have enough money.Do you want to pledge one of your countries or a power station��";
	std::string serveText = "broke";
	std::vector<std::string> operation = { "One of my countries.", "A power station." };

	Menu menu(mainText, operation, serveText);
	int n = menu.exec();
	//δ����� �� ��
}