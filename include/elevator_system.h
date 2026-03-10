#ifndef ELEVATOR_SYSTEM_H
#define ELEVATOR_SYSTEM_H

#include <queue>
#include <vector>

#include "elevator.h"
#include "request.h"

class ElevatorSystem
{
private:

    int floors;

    std::vector<Elevator> elevators;

    std::queue<Request> requests;

    int chooseBestElevator(const Request& req);

    void dispatchRequests();

public:

    ElevatorSystem(int numElevators, int floors);

    void externalRequest(int floor, bool up);

    void internalRequest(int elevatorId, int floor);

    void step();
};

#endif