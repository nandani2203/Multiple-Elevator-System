#include <iostream>
#include <thread>
#include <chrono>

#include "include/elevator_system.h"

using namespace std;

int main()
{
    cout << "Starting Multiple Elevator System Simulation\n";

    ElevatorSystem system(2, 10);

    system.externalRequest(3, true);  
    system.externalRequest(7, false);  

    system.internalRequest(0, 5);

    for (int step = 0; step < 25; step++)
    {
        cout << "\nSimulation Step: " << step + 1 << endl;

        system.step();

        this_thread::sleep_for(chrono::milliseconds(500));

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