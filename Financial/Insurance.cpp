#include "Insurance.h"

using namespace std;

Insurance::Insurance(int _SumInsured,
	int _premium,
	int _TimeLimit,
	int _AccountPeriod,
	Player* _owner) : SumInsured(_SumInsured),
	premium(_premium),
	TimeLimit(_TimeLimit),
	AccountPeriod(_AccountPeriod),
	month(0),
	owner(_owner) {}

void Insurance::MonthlyPayment()
{
	int money = owner->getMoney();

	string mainText = "Please complete the monthly payment of your insurance.";
	vector<string> operation = { "Pay it.", "Don't pay it." };
	string serveText = "monthly_payment";

	string mainText1 = "Are you sure to cancel your insurance?";
	vector<string> operation1 = { "Yes, I'm sure.", "No, I want to finish the payment.", "No, I want to pledge." };
	string serveText1 = "cancel";

	string mainText2 = "You don't have enough money.";
	string serveText2 = "poor";

	string mainText3 = "You have completed the payment of your insurance.";
	string serveText3 = "complete";

	int n = 0;
	Menu menu(mainText, operation, serveText);
	Menu menu1(mainText1, operation1, serveText1);

	while (n != 1)
	{
		n = menu.exec();

		if (n == 1 && money >= premium)
		{
			money -= premium;
			owner->setMoney(money);
			TimeLimit--;
			month++;
			if (TimeLimit == 0);
			Output::instance->print(mainText3, serveText3);
			return;
		}

		else if (n == 1 && money < premium)
		{
			Output::instance->print(mainText2, serveText2);
		}

		else
		{
			n = menu1.exec();
			if (n == 3)
				owner->broke();
		}
	}
