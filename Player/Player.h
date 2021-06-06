#ifndef PLAYER_PERSON_H
#define PLAYER_PERSON_H

#include <string>
#include <iostream>
#include "Menu.h"
#include "../Player/Output.h"
#include "../Ground/Ground.h"

#define N 7 //NΪ��ɫ����

///�����
class Player
{
private:
	std::string name;		//����ǳ�
	int money;				//ӵ�е��ֽ���
	int countryNum;			//ӵ�еĵز���Ŀ
	int powerStationNum;	//ӵ�еķ��糧��Ŀ
	int* colorCountryNum;	//������ɫ�ĵ�ӵ�е���Ŀ
	float luck;				//����ֵ��Ӱ��鿨�ĺû���
	int pause;				//��ͣ�غ���
	float myStockPrice;     //���˳��۹�Ʊ����
	int stockNum;           //���˳��й���
	int sellNum;            //���˹ҳ��Ĺ���
	Ground* position;		//ָ�������������λ��

public:
	Player(std::string _name) : name(_name),
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
	Player() : name("nmae"),
		money(50000000),
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
	float getLuck() { return luck; }
	int getPause() { return pause; }
	int getStockNum() { return stockNum; }
	float getmyStockPrice() { return myStockPrice; }
	int getsellellkNum() { return sellNum; }
	Ground* getPosition() { return position; }

	void setMoney(int _money);
	void setPosition(Ground* ground) { position = ground; }			//�ı����λ��
	void changePause(int num) { pause = pause + num; }				//����ͣnum�غ�
	void setLuck(float _luck) { luck = _luck; }						//�ı�����ֵ
	void setStockNum(int num) { stockNum = num; }                   //�����ֳֹ���
	void setmyStockPrice(float price) { myStockPrice = price; }     //������˹�Ʊ����
	void setSellNum(int num) { sellNum = num; }                     //������˹ҳ��Ĺ���

	void buyCountry();		//����յ�
	void buyPowerStation();	//���򷢵糧

	void bePaused() { pause--; };
	void show();
	void broke();			//�Ʋ�
};

#endif // !PERSON_H