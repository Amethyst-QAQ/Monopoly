#include"Chance.h".
#include"Fate.h"
#include"Person.h"
#include<iostream>
using namespace std;

class Chance_1 :public Chance                         //�ù�-1
{
public:
	Chance_1() :Chance("ɨ���ж�", 0) {}              //���캯������ʼ��Chance_1�����¼�����������ֵ
	void doEvent(Person& a)
	{
		cout << getName() << endl;     //��ӡ��������
		int temp = a.getHotelNumber();
		temp -= 1;
		a.setHotel(temp);
	}
};

class Fate_1 :public Fate                             //���糧+1
{
public:
	Fate_1():Fate("Ϊ������",5){}                     //���캯������ʼ��Fate_1�����¼�����������ֵ

	void doEvent(Person& a)
	{
		cout << "***"<<getName()<< "***" << endl;
		a.buyPowerStation();
	}
};