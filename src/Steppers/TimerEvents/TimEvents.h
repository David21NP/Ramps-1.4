#ifndef TimEvens_h
#define TimEvens_h

#include "../../util/pch.h"
#include <TimerOne.h>

#define EVENT_SIZE 100
#define SAMPLE_TIME_US 7500.0f
#define SAMPLE_TIME (SAMPLE_TIME_US/1000000.0f)
#define SAMPLE_FREQUENCY (1000000.0f/SAMPLE_TIME_US)

static void doNothing() {}

typedef void (*EventHandler)();
typedef struct _event
{
    EventHandler handler;
    bool toHandle;
} Event;

class TimEvents
{
private:
    TimEvents() {}
    ~TimEvents() {}

    Event AllEvents[EVENT_SIZE];

    void IInitEvents()
    {
        for (int i = 0; i < EVENT_SIZE; i++)
        {
            AllEvents[i].handler = doNothing;
            AllEvents[i].toHandle = false;
        }
    }
    void IAddEvent(EventHandler ev_handler)
    {
        static int counter = 0;
        AllEvents[counter].handler = ev_handler;
        AllEvents[counter].toHandle = true;
        if (counter < (EVENT_SIZE - 1))
            counter++;
        else
            counter = 0;
    }

    void IRemoveEvent(int pos)
    {
        AllEvents[pos].handler = doNothing;
        AllEvents[pos].toHandle = false;
    }

    void IEventLoop()
    {
        static long call_count = 0;
        EventHandler handler;
        for (int i = 0; i < EVENT_SIZE; i++)
        {
            if (AllEvents[i].toHandle)
            {
                handler = AllEvents[i].handler;
                removeEvent(i);
                handler();
            }
        }
        if (call_count < 10000000) call_count++;
        else call_count = 0;
    }

public:
    TimEvents(const TimEvents &) = delete;
    void operator=(const TimEvents &) = delete;

    static TimEvents &Get()
    {
        static TimEvents instance;
        return instance;
    }

    static void initEvents()
    {
        Get().IInitEvents();
        Timer1.initialize((long) SAMPLE_TIME_US);
        Timer1.attachInterrupt(eventLoop);
    }

    static void addEvent(EventHandler ev_handler) { Get().IAddEvent(ev_handler); }

    static void removeEvent(int pos) { Get().IRemoveEvent(pos); }

    static void eventLoop() { Get().IEventLoop(); }
};

#endif