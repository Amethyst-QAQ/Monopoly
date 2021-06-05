#include "CardsSuit.h"

void CardsSuit::getLuckVal(int player)   //计算幸运值，幸运值与抽到的卡片有关
{
	Person& p = players[player];
	float luck = p.getLuck();
	luck = 1 - luck * 0.9;              //计算luck值
										//好卡坏卡交替出现
	p.setLuck(luck);                    //更新Person的Luck值
}