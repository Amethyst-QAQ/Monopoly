#ifndef PLAYER_PERSON_H
#define PLAYER_PERSON_H

#include <iostream>
#include <string>
#include "../Ground/Country.h"
#include "../Ground/Ground.h"
#include "../Ground/PowerStation.h"

#define N 7 //NΪ��ɫ����

//�����
class Person
{
private:
	std::string name;		//����ǳ�
	int num;				//��ұ��
	int money;				//ӵ�е��ֽ���
	int countryNum;			//ӵ�еĵز���Ŀ
	int powerStationNum;	//ӵ�еķ��糧��Ŀ
	int* colorCountryNum;	//������ɫ�ĵ�ӵ�е���Ŀ
	float luck;				//����ֵ��Ӱ��鿨�ĺû���
	int pause;				//��ͣ�غ���
	Ground* position;		//ָ�������������λ��

public:
	Person(std::string _name, int _num) : name(_name), 
										  num(_num),
										  money(50000),
										  countryNum(0), 
										  powerStationNum(0),
										  luck(0),
										  pause(0),
										  position(nullptr)
	{
		colorCountryNum = new int[N];
		for (int i = 0; i < N; i++)
			colorCountryNum[i] = 0;
	}
	
	std::string getName() { return name; }
	int getMoney() { return money; }
	int getCountryNumber() { return countryNum; }
	int getPowerStationNumber() { return powerStationNum; }
	int getNumber() { return num; }
	float getLuck() { return luck; }
	int getPause() { return pause; }
	Ground* getPosition() { return position; }

	void setPosition(Ground* ground) { position = ground; }	//�ı����λ��
	void setPause(int num) { pause = num; }					//����ͣnum�غ�
	void setLuck(float _luck) { luck = _luck; }				//�ı�����ֵ
	void setHotel(int num) { hotel_num = num; }             //�ı��ù���
	void buyCountry(Country country) { country_num++; color[country.getColor()]++; }					//����յ�
	void buyPowerStation() { power_station_num++; }			//���򷢵糧
	void buildHouse() { house_num++; };						//�Ƿ���
	void buildHotel() { hotel_num++; house_num -= 2; };		//���ù�
};

#endif // !PERSON_H