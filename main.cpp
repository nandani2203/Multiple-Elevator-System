#include <iostream>
#include <thread>
#include <chrono>

#include "include/elevator_system.h"

using namespace std;

int main()
{
    cout << "Starting Multiple Elevator System Simulation\n";

    // Create system with 2 elevators and 10 floors
    ElevatorSystem system(2, 10);

    /*
    Initial external requests
    */
    system.externalRequest(3, true);   // floor 3 going up
    system.externalRequest(7, false);  // floor 7 going down

    /*
    Internal request example
    Passenger inside elevator 0 presses floor 5
    */
    system.internalRequest(0, 5);

    /*
    Run simulation loop
    */
    for (int step = 0; step < 25; step++)
    {
        cout << "\nSimulation Step: " << step + 1 << endl;

        system.step();

        // simulate time delay between elevator movements
        this_thread::sleep_for(chrono::milliseconds(500));

        /*
        Generate dynamic requests during simulation
        */
        if (step == 5)
        {
            cout << "\n[New Request] Floor 2 UP\n";
            system.externalRequest(2, true);
        }

        if (step == 10)
        {
            cout << "\n[New Request] Floor 9 DOWN\n";
            system.externalRequest(9, false);
        }
    }

    cout << "\nSimulation Finished\n";

    return 0;
}