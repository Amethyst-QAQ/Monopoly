#ifndef FINANCIAL_INSURANCE_H
#define FINANCIAL_INSURANCE_H

#include <iostream>
#include <string>

class Insurance
{
private:
	int SumInsured;	//����
	int premium;	//����
	int month;		//����ʱ��
	int TimeLimit;	//��Чʱ��

public:
	Insurance(int _SumInsured, int _premium, int _month, int _TimeLimit);

	int getSumInsured() { return SumInsured; }
	int getPremium() { return premium; }
	int getMonth() { return month; }
	int getTimeLimit() { return TimeLimit; }

	void setSumInsured(int sum) { SumInsured = sum; }
	void setPremium(int _premium) { premium = _premium; }
	void setMonth(int _month) { month = _month; }
	void setTimeLimit(int _TimeLimit) { TimeLimit = _TimeLimit; }

	void Pay()
	{

	}
};

#endif