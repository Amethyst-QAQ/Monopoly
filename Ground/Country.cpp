#include "Country.h"
using namespace std;

Country::Country(std::string _name, 
				int _price, 
				int _toll, 
				int _color,
				int _house_price, 
				int _hotel_price) : 
									GroundWithPrice(_price),
									name(_name),
									toll(_toll),
									color(_color),
									housePrice(_house_price),
									hotelPrice(_hotel_price) {}
									


void Country::onStepped(int player)
{
	GroundWithPrice::onStepped(player);

}

void Country::buy(int player)
{
	Person& p = players[player];
	int money = p.getMoney();
	if (money < price)
		cout << "You don't have enough money." << endl;
	else
	{
		cout << "Successfully bought!" << endl;
		money -= price;
		p.setMoney(money);
		p.buyCountry();
	}
}

void Country::HouseBuild()
{
	house++;
}

void Country::HotelBuild()
{
	hotel++;
	house -= 2;
}
