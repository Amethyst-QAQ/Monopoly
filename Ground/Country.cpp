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
