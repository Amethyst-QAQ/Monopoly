#include "Country.h"
using namespace std;

Country::Country(std::string _name, 
				int _price, 
				int _toll, 
				int _owner,
				int _color,
				int _house_price, 
				int _hotel_price)
{
	setName(_name);
	setPrice(_price);
	setToll(_toll);
	setColor(color);
	setHousePrice(_house_price);
	setHotelPrice(_hotel_price);

	house = 0;
	hotel = 0;
	owner = 0;		//编号0代表银行
	pledge = false; //false代表未出售
}

void Country::onStepped()
{
	Ground::onStepped();
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

void Country::Hypothecate()
{
	pledge = true;
}
