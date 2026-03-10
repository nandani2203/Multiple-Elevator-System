#ifndef ELEVATOR_SYSTEM_H
#define ELEVATOR_SYSTEM_H

#include <memory>
#include <queue>
#include <vector>

#include "elevator.h"
#include "request.h"

class ElevatorSystem
{
private:

    int floors;

    std::vector<std::unique_ptr<Elevator>> elevators;

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