#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <set>

using namespace std;

class Elevator
{
public:

    enum State
    {
        IDLE,
        MOVING_UP,
        MOVING_DOWN
    };

private:

    int id;
    int currentFloor;
    int totalFloors;

    State state;

    set<int> upStops;
    set<int> downStops;

public:

    Elevator(int id, int totalFloors);

    void addStop(int floor);

    void step();

    int getCurrentFloor() const;

    State getState() const;

    int getId() const;
};

#endif