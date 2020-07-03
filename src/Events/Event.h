#ifndef Event_h
#define Event_h

#include "../util/pch.h"

typedef void (*EventHandler)();
//typedef void (Stepper::* s_EventHandler)();



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