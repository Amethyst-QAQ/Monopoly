#ifndef FINANCIAL_INSURANCE_H
#define FINANCIAL_INSURANCE_H

#include <string>
#include "../Player/Menu.h"
#include "../Player/Player.h"
#include "../Player/Output.h"

extern Player* players;

class Insurance
{
private:
	int SumInsured;		//保额
	int premium;		//保费
	int TimeLimit;		//交费时长
	int AccountPeriod;	//生效时长
	int month;			//已交时长
	int owner;

public:
	Insurance(int _SumInsured, int _premium, int _TimeLimit, int _AccountPeriod, int _owner);
	~Insurance() {};

	int getSumInsured() { return SumInsured; }
	int getPremium() { return premium; }
	int getMonth() { return TimeLimit; }
	int getTimeLimit() { return AccountPeriod; }

	void setSumInsured(int sum) { SumInsured = sum; }
	void setPremium(int _premium) { premium = _premium; }
	void setTimeLimit(int _TimeLimit) {TimeLimit = _TimeLimit; }
	void setAccountPeriod(int _AccountPeriod) {AccountPeriod = _AccountPeriod; }
	void setOwner(int _owner) { owner = _owner; }

	void MonthlyPayment();		//每回合支付保险
};

#endif