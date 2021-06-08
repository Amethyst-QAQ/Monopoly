#include "FateSuit.h"

void FateSuit::show()
{
	Fate* card = nullptr;
	for (auto i = suit.begin(); i != suit.end(); i++)
	{
		*card = *i;
		card->show();
	}
}

Fate* FateSuit::draw(Player* player)
{
	Fate* card = nullptr;				//�����ҿ���ָ��
	srand((unsigned int)time(NULL));	//����ϵͳʱ�����������
	if (player->getLuck() >= 0.6 && player->getLuck() <= 1)
	{
		int n = rand() % 9;	//n��ʾ���ĵȼ�
		switch (n)
		{
		case 4:
		case 5:
			n = 3;			//��n = 4 or 5ʱ���鵽�Ŀ���Ϊ3��
			break;
		case 6:
		case 7:
			n = 4;			//��n = 6 or 7ʱ���鵽�Ŀ���Ϊ4��
			break;
		case 8:
			n = 5;			//��n = 8ʱ���鵽�Ŀ�Ϊ5��
			break;
		default:
			break;
		}

		int m = rand();		//m��ʾ���ı��
		switch (n)
		{
		case 0:
			m = 0;			//�ȼ�Ϊ0�Ŀ��ƹ���1��
			break;
		case 1:
			m %= 2;			//�ȼ�Ϊ1�Ŀ��ƹ���2��
			break;
		case 2:
			m %= 3;			//�ȼ�Ϊ2�Ŀ��ƹ���3��
			break;
		case 3:
		case 4:
			m %= 8;			//�ȼ�Ϊ3��4�Ŀ��ƹ���8��
			break;
		case 5:
			m %= 3;			//�ȼ�Ϊ5�Ŀ��ƹ���5��
		}

		//�����ƿ��ҵ���Ӧ��
		for (auto i = suit.begin(); i != suit.end(); i++)
		{
			*card = *i;
			if (card->getNum() == m && card->getVal() == n)
				return card;
		}
	}
}