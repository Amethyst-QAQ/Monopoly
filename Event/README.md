# �¼�ϵͳ

�¼�ϵͳ���¼��ࡢ���������¼�����ϵͳ��ɡ��¼��������¼�����ϵͳ�����¼����͸�ÿ����������

����Ϊ�¼�ϵͳ�ļ���ʹ��ָ�ϡ�

## ע���¼���

Ϊ�˷����¼�����Ҫע���¼��ࡣ

�¼���������κ��࣬��������¼������Ϊֻ��������setter�����ļ��ࡣ

�¼�����Լ̳������࣬�����齫�¼���������̳����������඼ע��Ϊ�¼��ࡣ

���ڸ��಻���¼�����࣬ʹ��`Event.h` �е�`REGISTER_INITIAL_EVENT(����)`������ע���Ϊ�¼��ࡣ

���ڸ������¼�����࣬ʹ��`Event.h` �е�`REGISTER_CHILD_EVENT(����, ������)`������ע���Ϊ�¼��ࡣ

������һ���򵥵�ʾ����

```c++
#include "Event.h"

class A
{
private:
    int foo;
public:
    A(int _foo) : foo(_foo){}
    int getFoo() { return foo; }
};

REGISTER_INITIAL_EVENT(A);

class B : public A
{
private:
    int bar;
public:
    B(int _foo, int _bar) : A(_foo), bar(_bar){}
    int getBar() { return bar; }
};

REGISTER_CHILD_EVENT(B);
```

## �����¼�

ʹ��`Event.h`�е�`EMIT_EVENT(className, obj, time)`������һ���¼���

`className`ΪҪ���͵��¼������ơ�

`obj`ΪҪ���͵�ʱ�����ע�⣬`obj`������`className`ָ������Ķ���ָ�롣

`time`Ϊ����Ϸ���ʶ�������ⳤ�Ȳ�Ϊ1�ĺϷ���ʶ��ȥ�����׸��ַ�������ָʾͬһ�������ڵڼ���ʹ�ø����ͬһ�������µ�����`EMIT_EVENT`����ܾ�����ͬ��`time`���Ƽ�������Ϊ���������´������ִ�д�����

�¼����ͺ󣬽��ᱻ���������ա�

������һ���򵥵�ʾ��������������һ��ע���¼���`A`��

```c++
int main()
{
    A* a = new A(123);
    A* b = new A(456);
    EMIT_EVENT(A, a, 1);
    EMIT_EVENT(A, b, 2);
}
```

## �����¼�

ʹ��`Listener.h`�е�`CREATE_LISTENER(type, func, priority)`������һ���������������¼���

`type`ΪҪ������ʱ�����͡�

`func`Ϊ�¼�������ִ�еĺ���ָ�룬�������¼�����Ϊ`T`����ô`func`Ϊ`void(*)(T*)`���͡�

`priority`��һ��`int`����������Ϊ�����������ȼ���

���ĳ�����¼��ļ����������󣬱������������и������¼���ֱ������ʹ��`delete`ɾ��������ͬһ�¼������м�������ִ��˳��Ϊ�Ӽ�������ļ���������������ļ������������ȼ��ߵļ����������ȼ��͵ļ�������

���������յ��¼��󣬿���ʹ��`EventHandler.h`�е�`EventHandler::instance->finishEvent()`��Ա���������¼�������¼���ĳ���������ڱ���������ô����֮��ִ�еļ�������������յ����¼���

������һ���򵥵�ʾ�������������һ��ע���¼���`A`��`B`��

```c++
void onEvent1(B* event)
{
    cout << event->getBar();
}

void onEvent2(B* event);
{
    cout << event->getFoo();
    EventHandler::instance->finishEvent();
}

void onEvent3(A* event)
{
    cout << event->getFoo();
}

int main()
{
    Listener* a = CREATE_LISTENER(B, onEvent1, 4);
    Listener* b = CREATE_LISTENER(B, onEvent2, 5);
    Listener* c = CREATE_LISTENER(A, onEvent3, 1);
    
    //�˴�������һ��B�����¼�
    
    delete a;
    delete b;
    delete c;
}
```

�����������У�����`c`������`A`����`B`��ĸ��࣬����`c`�ĺ���`onEvent3`������ִ�С�����`b`�����ȼ�����`a`������`onEvent2`��`onEvent1`��ִ�С������¼���`onEvent2`�б�������ʵ����`onEvent1`����ִ�С�