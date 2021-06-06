#ifndef GROUND_MAP_H
#define GROUND_MAP_H

#include"Ground.h"
#include"Beginning.h"

//地图通过结构体链表实现

template <class T>
struct node                                 //链表结点的结构体定义
{

	T ground;							//指向一个格子类的对象
	node* next;								//指向按地图前进路线的下一个位置
	node* last;								//指向按地图前进的相反方向路线的下一个位置
	node(T& _ground) : ground(_ground), next(nullptr),last(nullptr) {}
};

class Map
{
private:
public:
	node<Country>* head;

};

#endif // !MAP_H