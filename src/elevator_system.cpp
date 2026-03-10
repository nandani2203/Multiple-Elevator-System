#include "../include/elevator_system.h"
#include "../include/simulator.h"

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

ElevatorSystem::ElevatorSystem(int numElevators, int floors)
{
    this->floors = floors;

    for (int i = 0; i < numElevators; i++)
    {
        elevators.push_back(Elevator(i, floors));;
    }
}


void ElevatorSystem::externalRequest(int floor, bool up)
{
    if (floor < 0 || floor >= floors)
    {
        cout << "Invalid floor request\n";
        return;
    }

    requests.push(Request(floor, up, false));
}


void ElevatorSystem::internalRequest(int elevatorId, int floor)
{
    if (elevatorId < 0 || elevatorId >= elevators.size())
        return;

    elevators[elevatorId].addStop(floor);
}


int ElevatorSystem::chooseBestElevator(const Request& req)
{
    int bestElevator = -1;
    int bestScore = INT_MAX;

    for (int i = 0; i < elevators.size(); i++)
    {
        int elevatorFloor = elevators[i].getCurrentFloor();
        int distance = abs(elevatorFloor - req.floor);

        int score = distance * 10; 
        Elevator::State state = elevators[i].getState();

        if (state == Elevator::IDLE)
        {
            score -= 5;
        }
        else if (state == Elevator::MOVING_UP)
        {
            if (req.is_up && req.floor >= elevatorFloor)
                score -= 10;
            else
                score += 15; 
        }
        else if (state == Elevator::MOVING_DOWN)
        {
            if (!req.is_up && req.floor <= elevatorFloor)
                score -= 10;
            else
                score += 15;
        }

        if (score < bestScore)
        {
            bestScore = score;
            bestElevator = i;
        }
    }

    return bestElevator;
}


void ElevatorSystem::dispatchRequests()
{
    while (!requests.empty())
    {
        Request req = requests.front();
        requests.pop();

        int elevatorIndex = chooseBestElevator(req);

        if (elevatorIndex != -1)
        {
            elevators[elevatorIndex].addStop(req.floor);
        }
    }
}


void ElevatorSystem::step()
{
    dispatchRequests();

    for (auto &elevator : elevators)
    {
        elevator.step();
    }

    Simulator::printSystem(elevators);
}