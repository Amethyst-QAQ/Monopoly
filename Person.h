#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<string>

class Person
{
protected:
	std::string name;
	int money;
	int country_num;
	int house_num;
	int hotel_num;
	int num;
	float luck;

public:
	Person(std::string _name, int _num) :name()

		std::string getName() { return name; }
	int getMoney() { return money; }
	int getCountryNumber() { return country_num; }
	int getHouseNumber() { return house_num; }
	int getHotelNumber() { return hotel_num; }
	int getNumber() { return num; }
	float getLuck() { return luck; }


};

#endif // !PERSON_H