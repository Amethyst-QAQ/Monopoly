#include"Chance.h".
#include"Fate.h"
#include"Person.h"
#include<iostream>
using namespace std;

class Chance_1 :public Chance                         //旅馆-1
{
public:
	Chance_1() :Chance("扫黄行动", 0) {}              //构造函数，初始化Chance_1卡的事件名称与幸运值
	void doEvent(Person& a)
	{
		cout << getName() << endl;     //打印招数名字
		int temp = a.getHotelNumber();
		temp -= 1;
		a.setHotel(temp);
	}
};

class Fate_1 :public Fate                             //发电厂+1
{
public:
	Fate_1():Fate("为爱发电",5){}                     //构造函数，初始化Fate_1卡的事件名称与幸运值

	void doEvent(Person& a)
	{
		cout << "***"<<getName()<< "***" << endl;
		a.buyPowerStation();
	}
};