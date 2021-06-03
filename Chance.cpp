#include"Chance.h"
#include<iostream>
using namespace std;

int luck;
int power_station;
Chance::Func(int choice)
{
	switch (choice)
	{
	case 0:  //±ª»À≥≠º“
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