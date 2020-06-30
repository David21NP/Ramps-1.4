#ifndef Event_h
#define Event_h

#include "../util/pch.h"
#include <QueueArray.h>
#include "../Stepper/Stepper.h"

typedef void (*EventHandler)();
typedef void (Stepper::* s_EventHandler)();

class Event
{
private:
    Event() {}

    QueueArray<EventHandler> pendingEvents;

    QueueArray<EventHandler> IGetEvents() { return pendingEvents; }

    QueueArray<s_EventHandler> stepperEvents;

    QueueArray<s_EventHandler> IGetSEvents() { return stepperEvents; }

public:
    //~Event();

    Event(const Event &) = delete;
    Event& operator=(const Event &) = delete;

    static QueueArray<EventHandler> GetEvents() { return Get().IGetEvents(); }

    static QueueArray<s_EventHandler> GetSEvents() { return Get().IGetSEvents(); }

    static Event &Get()
    {
        static Event Instance;
        return Instance;
    }

    static void AddEvent(EventHandler ev_handler)
    {
        Get().GetEvents().enqueue(ev_handler);
    }

    static void AddEvent(s_EventHandler ev_handler)
    {
        Get().GetSEvents().enqueue(ev_handler);
    }
};

#endif