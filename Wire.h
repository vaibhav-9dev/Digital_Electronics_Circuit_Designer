#ifndef WIRE_H
#define WIRE_H

#include "Component.h"

class Wire
{
private:
    Component* source;
    Component* destination;
    int signal;

public:
    Wire(Component* source = nullptr,
         Component* destination = nullptr);

    void setSignal(int value);

    int getSignal() const;

    Component* getSource() const;

    Component* getDestination() const;
};

#endif