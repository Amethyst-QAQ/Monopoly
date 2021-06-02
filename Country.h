#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <string>

#define PRICE_1 0        //���ݼ۸�
#define PRICE_2 0		 //�ùݼ۸�

//�ز���
class Country
{
private:
	std::string name;   //�ز�����
	int price;          //�ز��۸�
	int toll;           //��·��
	int house_price;    //�������ݵļ۸�
	int hotel_price;    //�����ùݵļ۸�
	int house;          //������
	int hotel;          //�ù���
	int owner;          //������
	bool pledge;        //�Ƿ��ѵ�Ѻ

public:
	Country();
	std::string getName() { return name; }
	int getPrice() { return price; }
	int getToll() { return toll + PRICE_1 * house + PRICE_2 * hotel; }
	int getHouse() { return house; }
	int getHotel() { return hotel; }
	int getOwner() { return owner; }
	bool getPledge() { return pledge; }

	void Build();
	void Hypothecate();
};

#endif