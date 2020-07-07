#include "Event.h"

template <typename T, int max_ev>
Event<T, max_ev>::Event()
{
    m_size = 0;
}

template <typename T, int max_ev>
Event<T, max_ev>::~Event()
{
}

template <typename T, int max_ev>
int Event<T, max_ev>::GetSize()
{
    return m_size;
}

template <typename T, int max_ev>
void Event<T, max_ev>::AddLast(T ev_handler)
{
    AddAt(ev_handler, m_size);
}

template <typename T, int max_ev>
void Event<T, max_ev>::AddAt(T ev_handler, int index)
{
    if ((index < (max_ev)) && (index >= 0))
    {
        m_size++;
        m_event[index] = ev_handler;
        for (int i = (m_size-1); i > index; i--)
        {
            m_event[i] = m_event[i-1];
        }
    }
}

template <typename T, int max_ev>
void Event<T, max_ev>::RemoveLast()
{
    RemoveAt(m_size-1);
}

template <typename T, int max_ev>
void Event<T, max_ev>::RemoveFirst()
{
    RemoveAt(0);
}

template <typename T, int max_ev>
void Event<T, max_ev>::RemoveAt(int index)
{
    if ((index < (m_size)) && (index >= 0))
    {
        m_size--;
        for (int i = index; i < m_size; i++)
        {
            m_event[i] = m_event[i + 1];
        }
    }
}