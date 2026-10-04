#include "Wire.h"

Wire::Wire(Component* source, Component* destination)
    : source(source),
      destination(destination),
      signal(0)
{
}

void Wire::setSignal(int value)
{
    signal = value;
}

int Wire::getSignal() const
{
    return signal;
}

Component* Wire::getSource() const
{
    return source;
}

Component* Wire::getDestination() const
{
    return destination;
}