#ifndef Event_h
#define Event_h

#include "../util/pch.h"

typedef void (*EventHandler)();
//typedef void (Stepper::* s_EventHandler)();

template<typename T>
struct Node
{
    T data;
    Node* next;
};

template<typename T>
class SimpleQueue
{
private:
    Node<T> first;
public:
    SimpleQueue();
    ~SimpleQueue();
    void push(T value);
    T pop();
};

template<typename T>
SimpleQueue<T>::SimpleQueue()
{
    first.data = NULL;
    first.next = nullptr;
}

template<typename T>
SimpleQueue<T>::~SimpleQueue()
{
}

template<typename T>
void SimpleQueue<T>::push(T value)
{
}

template<typename T>
T SimpleQueue<T>:: pop()
{
}


template <typename T, int max_ev>
class Event
{
private:
    T m_event[max_ev];
    int m_size;
public:
    Event();
    ~Event();

    int GetSize();
    void AddLast(T ev_handler);
    void AddAt(T ev_handler, int index);
    void RemoveLast();
    void RemoveFirst();
    void RemoveAt(int index);
};

#endif