#include"Chance.h"
#include<iostream>
using namespace std;

int luck;
int power_station;
Chance::Chance()
{
	m_Eventname[0] = "Confiscate the property";  //被人抄家
	m_Eventname[1] = "";
	m_Eventname[2] = "";
	m_Eventname[3] = "";
	m_Eventname[4] = "";
	m_Eventname[5] = "";
	m_Eventname[6] = "";
	m_Eventname[7] = "";
	m_Eventname[8] = "";
	m_Eventname[9] = "";
}

Chance::Func(int choice)
{
	switch (choice)
	{
	case 0:  //被人抄家
		cout << "Power Station -1" << endl;
		power_station -= 1;
	case 1:
		cout << "" << endl;
	case 9:
		cout << "Power Station +1" << endl;
	default:
		break;
	}
}