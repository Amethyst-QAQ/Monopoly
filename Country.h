#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <string>
#include "Ground.h"

#define PRICE_1 0        //���ݼ۸�
#define PRICE_2 0		 //�ùݼ۸�

//�ز��࣬�̳и�����
class Country : public Ground
{
private:
	std::string name;   //�ز�����
	int price;          //�ز��۸�
	int toll;           //��·��
	int house_price;    //�������ݵļ۸�
	int hotel_price;    //�����ùݵļ۸�
	int house;          //����������������
	int hotel;          //�ù�������������
	int owner;          //�����ߣ�0��������
	int color;			//��ɫ��ӵ��ͬɫ�����й��ҵ����ͼ��չ�·��Ϊԭ����3����
	bool pledge;        //�Ƿ��ѵ�Ѻ

public:
	Country(std::string _name, int _price, int _toll, int _owner, int color, int _house_price, int _hotel_price);

	void setName(std::string _name) { name = _name; }
	void setPrice(int _price) { price = _price; }
	void setToll(int _toll) { toll = _toll; }
	void setOwner(int _owner) { owner = _owner; } //�൱�ڹ�������·��ʱֱ�Ӽ��owner�ǲ���0����
	void setColor(int _color) { color = _color; }
	void setHousePrice(int _house_price) { house_price = _house_price; }
	void setHotelPrice(int _hotel_price) { hotel_price = _hotel_price; }

	std::string getName() { return name; }
	int getPrice() { return price; }
	int getToll() { return toll + PRICE_1 * house + PRICE_2 * hotel; }
	int getHouse() { return house; }
	int getHotel() { return hotel; }
	int getOwner() { return owner; }
	bool getPledge() { return pledge; }
	int getColor() { return color; }

	void HouseBuild();	//���췿��
	void HotelBuild();	//�����ù�
	void Hypothecate();	//��Ѻ����
};

#endif