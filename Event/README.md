# 事件系统

事件系统由事件类、监听器与事件处理系统组成。事件发生后，事件处理系统将把事件类送给每个监听器。

以下为事件系统的简易使用指南。

## 注册事件类

为了发送事件，需要注册事件类。

事件类可以是任何类，但建议把事件类设计为只具有若干setter函数的简单类。

事件类可以继承其它类，但建议将事件类的整个继承树中所有类都注册为事件类。

对于父类不是事件类的类，使用`Event.h` 中的`REGISTER_INITIAL_EVENT(类名)`来把类注册成为事件类。

对于父类是事件类的类，使用`Event.h` 中的`REGISTER_CHILD_EVENT(类名, 父类名)`来把类注册成为事件类。

以下是一个简单的示例：

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

## 发送事件

使用`Event.h`中的`EMIT_EVENT(className, obj, time)`来发送一个事件。

`className`为要发送的事件类名称。

`obj`为要发送的时间对象。注意，`obj`必须是`className`指明的类的对象指针。

`time`为任意合法标识符或任意长度不为1的合法标识符去掉其首个字符，用于指示同一作用域内第几次使用该命令。同一作用域下的所有`EMIT_EVENT`命令不能具有相同的`time`。推荐将其设为该作用域下此命令的执行次数。

事件发送后，将会被监听器接收。

以下是一个简单的示例（假设已如上一节注册事件类`A`）

```c++
int main()
{
    A* a = new A(123);
    A* b = new A(456);
    EMIT_EVENT(A, a, 1);
    EMIT_EVENT(A, b, 2);
}
```

## 监听事件

使用`Listener.h`中的`CREATE_LISTENER(type, func, priority)`来创建一个监听器并监听事件。

`type`为要监听的时间类型。

`func`为事件发生后执行的函数指针，若监听事件类型为`T`，那么`func`为`void(*)(T*)`类型。

`priority`是一个`int`类型整数，为监听器的优先级。

针对某类型事件的监听器创建后，便会持续监听所有该类型事件，直到它被使用`delete`删除。对于同一事件，所有监听器的执行顺序为从监听父类的监听器到监听子类的监听器，从优先级高的监听器到优先级低的监听器。

监听器接收到事件后，可以使用`EventHandler.h`中的`EventHandler::instance->finishEvent()`成员函数结束事件。如果事件在某个监听器内被结束，那么在它之后执行的监听器都不会接收到此事件。

以下是一个简单的示例（假设已如第一节注册事件类`A`、`B`）

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
    
    //此处发生了一个B类型事件
    
    delete a;
    delete b;
    delete c;
}
```

在以上例子中，由于`c`监听的`A`类是`B`类的父类，所以`c`的函数`onEvent3`会最先执行。由于`b`的优先级高于`a`，所以`onEvent2`比`onEvent1`先执行。由于事件在`onEvent2`中被结束，实际上`onEvent1`不会执行。