#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<string>
#include"Country.h"

#define N 7 //NΪ��ɫ����

//�����
class Person
{
private:
	std::string name;		//����ǳ�
	int num;				//��ұ��
	int money;				//ӵ�е��ֽ���
	int country_num;		//ӵ�еĵز���Ŀ
	int house_num;			//ӵ�еķ�������
	int hotel_num;			//ӵ�е��ù�����
	int power_station_num;	//ӵ�еķ��糧��Ŀ
	int* color;				//������ɫ�ĵ�ӵ�е���Ŀ
	float luck;				//����ֵ��Ӱ��鿨�ĺû���

public:
	Person(std::string _name, int _num) : name(_name), 
										  num(_num),
										  money(50000),
										  country_num(0), 
										  house_num(0),
										  hotel_num(0),
										  power_station_num(0),
										  luck(0) 
	{
		color = new int[N];
		for (int i = 0; i < N; i++)
			color[i] = 0;
	}
	
	std::string getName() { return name; }
	int getMoney() { return money; }
	int getCountryNumber() { return country_num; }
	int getHouseNumber() { return house_num; }
	int getHotelNumber() { return hotel_num; }
	int getPowerStationNumber() { return power_station_num; }
	int getNumber() { return num; }
	float getLuck() { return luck; }

	void setLuck(float _luck) { luck = _luck; }				//�ı�����ֵ
	void buyCountry(Country country) { country_num++; color[country.getColor()]++; }					//����յ�
	void buyPowerStation() { power_station_num++; }			//���򷢵糧
	void buildHouse() { house_num++; };						//�Ƿ���
	void buildHotel() { hotel_num++; house_num -= 2; };		//���ù�
};

#endif // !PERSON_H