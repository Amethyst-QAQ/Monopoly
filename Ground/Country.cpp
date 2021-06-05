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
									hotel(0),
									house(0),
									housePrice(_house_price),
									hotelPrice(_hotel_price) {}
									


void Country::onStepped(int player)
{
	Person& p = players[player];

	GroundWithPrice::onStepped(player);

	if (owner != 0)
	{
		if (owner == player)
		{
			string mainText = "The ground is yours.";
			vector<string> operation = { "Build a house", "Build a hotel", "Exit" };
			string serverText = "buy_ground";

			int n = 0;
			Menu menu(mainText, operation, serverText);
			while (n != 3)
			{
				n = menu.exec();

				switch (n)
				{
				case 1:
					if (house < 4)
						HouseBuild();
					else
						cout << "There are too many houses!" << endl;
					break;
				case 2:
					if (house < 4)
						cout << "There are not enough houses!" << endl;
					else if (hotel == 1)
						cout << "There is a hotel already!" << endl;
					else
						HotelBuild();
					break;
				case 3:
					return;
				}
			}
		}
		else
		{
			string name = p.getName();
			int price = getToll();

			string Text = "This is " + name + "'s country.You have to pay " + to_string(price) + "yuan as tolls.";
			string serveText = "pay_tool";

			Output::instance->print(Text, serveText);;


			int money = p.getMoney();
			money -= price;
			p.setMoney(money);
			
			p.broke();
		}
	}
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
	Person& p = players[owner];
	int money = p.getMoney();
	if (money < housePrice)
		cout << "You don't have enough money." << endl;
	else
	{
		cout << "Successfully built a hotel here!" << endl;
		money -= housePrice;
		house++;
		p.setMoney(money);
	}
}

void Country::HotelBuild()
{
	Person& p = players[owner];
	int money = p.getMoney();
	if (money < hotelPrice)
		cout << "You don't have enough money." << endl;
	else
	{
		cout << "Successfully built a house here!" << endl;
		money -= hotelPrice;
		hotel++;
		house -= 4;
		p.setMoney(money);
	}
}
