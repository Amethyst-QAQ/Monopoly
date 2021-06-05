#ifndef GROUND_COUNTRY_H
#define GROUND_COUNTRY_H

#include <iostream>
#include <string>
#include "GroundWithPrice.h"
#include "../Player/Person.h"

#define PRICE_1 0        //���ݼ۸�
#define PRICE_2 0		 //�ùݼ۸�

extern bool isServer;

///�ز��࣬�̳и�����
class Country : public GroundWithPrice
{
private:
	std::string name;   //�ز�����
	int toll;           //��·��
	int housePrice;     //�������ݵļ۸�
	int hotelPrice;     //�����ùݵļ۸�
	int house;          //����������������
	int hotel;          //�ù�������������
	int color;			//��ɫ��ӵ��ͬɫ�����й��ҵ����ͼ��չ�·��Ϊԭ����3����
	
public:
	Country(std::string _name, int _price, int _toll, int color, int _house_price, int _hotel_price);

	void onStepped(int player);									//·����ʱ����ã����������˵�

	void setName(std::string _name) { name = _name; }
	void setToll(int _toll) { toll = _toll; }
	void setColor(int _color) { color = _color; }
	void setHousePrice(int _house_price) { housePrice = _house_price; }
	void setHotelPrice(int _hotel_price) { hotelPrice = _hotel_price; }

	std::string getName() { return name; }
	int getToll() { return toll + PRICE_1 * house + PRICE_2 * hotel; }
	int getHouse() { return house; }
	int getHotel() { return hotel; }
	int getColor() { return color; }

	void buy(int player);

	void HouseBuild();	//���췿��
	void HotelBuild();	//�����ù�
};

#endif