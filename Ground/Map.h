#ifndef GROUND_MAP_H
#define GROUND_MAP_H

#include"Ground.h"
#include"Beginning.h"

//��ͼͨ���ṹ������ʵ��

template <class T>
struct node                                 //������Ľṹ�嶨��
{

	T ground;							//ָ��һ��������Ķ���
	node* next;								//ָ�򰴵�ͼǰ��·�ߵ���һ��λ��
	node* last;								//ָ�򰴵�ͼǰ�����෴����·�ߵ���һ��λ��
	node(T& _ground) : ground(_ground), next(nullptr),last(nullptr) {}
};

class Map
{
private:
public:
	node<Country>* head;

};

#endif // !MAP_H