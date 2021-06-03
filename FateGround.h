#ifndef FATEGROUND_H
#define FATEGROUND_H

//命运格子类
class FateGround
{
public:
	bool onFground() { return 1; }         //经过幸运格子
	bool Not_onFground() { return 0; }     //路过幸运格子
};
#endif // !FATEGROUND_H

