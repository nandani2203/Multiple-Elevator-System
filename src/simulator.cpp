#include "../include/simulator.h"

#include <iostream>

using namespace std;

void Simulator::printSystem(const vector<unique_ptr<Elevator>>& elevators)
{
    cout << "\n---------------------------\n";
    cout << "     Elevator System\n";
    cout << "---------------------------\n";

    for (const auto& elevator : elevators)
    {
        cout << "Elevator " << elevator->getId()
             << " | Floor: " << elevator->getCurrentFloor()
             << " | State: ";

        Elevator::State state = elevator->getState();

        if (state == Elevator::IDLE)
            cout << "IDLE";
        else if (state == Elevator::MOVING_UP)
            cout << "MOVING UP";
        else
            cout << "MOVING DOWN";

        cout << endl;
    }

    cout << "---------------------------\n";
}