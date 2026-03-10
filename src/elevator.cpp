#include "../include/elevator.h"

#include <iostream>

using namespace std;

Elevator::Elevator(int id, int totalFloors)
{
    this->id = id;
    this->totalFloors = totalFloors;
    this->currentFloor = 0;
    this->state = IDLE;
}

void Elevator::addStop(int floor)
{
    if (floor == currentFloor)
        return;

    if (floor > currentFloor)
        upStops.insert(floor);
    else
        downStops.insert(floor);

    if (state == IDLE)
    {
        if (!upStops.empty())
            state = MOVING_UP;
        else if (!downStops.empty())
            state = MOVING_DOWN;
    }
}

void Elevator::step()
{
    if (state == IDLE)
        return;

    if (state == MOVING_UP)
    {
        if (currentFloor < totalFloors - 1)
            currentFloor++;

        if (upStops.count(currentFloor))
        {
            upStops.erase(currentFloor);

            cout << "Elevator " << id
                 << " stopping at floor "
                 << currentFloor << endl;
        }

        if (upStops.empty())
        {
            if (!downStops.empty())
                state = MOVING_DOWN;
            else
                state = IDLE;
        }
    }
    else if (state == MOVING_DOWN)
    {
        if (currentFloor > 0)
            currentFloor--;

        if (downStops.count(currentFloor))
        {
            downStops.erase(currentFloor);

            cout << "Elevator " << id
                 << " stopping at floor "
                 << currentFloor << endl;
        }

        if (downStops.empty())
        {
            if (!upStops.empty())
                state = MOVING_UP;
            else
                state = IDLE;
        }
    }
}

int Elevator::getCurrentFloor() const
{
    return currentFloor;
}

Elevator::State Elevator::getState() const
{
    return state;
}

int Elevator::getId() const
{
    return id;
}