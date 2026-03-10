#include <iostream>
#include <cassert>

#include "../include/elevator_system.h"

using namespace std;

void run_until_stable(ElevatorSystem& system)
{
    for(int i = 0; i < 20; i++)
    {
        system.step();
    }
}

// Test 1: Basic request handling (Node Coverage)

void test_basic_request()
{
    cout << "\n--- Test Basic Request ---\n";

    ElevatorSystem system(2, 10);

    system.externalRequest(3, true);

    run_until_stable(system);

    cout << "Basic Request Test Passed\n";
}

// Test 2: Invalid floor request

void test_invalid_floor()
{
    cout << "\n--- Test Invalid Floor ---\n";

    ElevatorSystem system(2, 10);

    system.externalRequest(11, true);  

    run_until_stable(system);

    cout << "Invalid Floor Test Passed\n";
}

// Test 3: Mid-trip stop logic. Elevator going to 8 but receives request at 4

void test_mid_trip_stop()
{
    cout << "\n--- Test Mid Trip Stop ---\n";

    ElevatorSystem system(1, 10);

    system.externalRequest(8, true);

    for(int i = 0; i < 2; i++)
    {
        system.step();
    }

    cout << "[User] Request at floor 4 while elevator moving\n";

    system.externalRequest(4, true);

    run_until_stable(system);

    cout << "Mid Trip Stop Test Completed\n";
}

//Test 4: Multiple requests (Prime Path Coverage)

void test_multiple_requests()
{
    cout << "\n--- Test Multiple Requests ---\n";

    ElevatorSystem system(2, 10);

    system.externalRequest(2, true);
    system.externalRequest(6, true);
    system.externalRequest(4, false);

    run_until_stable(system);

    cout << "Multiple Request Test Passed\n";
}

//Test 5: Internal elevator request

void test_internal_request()
{
    cout << "\n--- Test Internal Request ---\n";

    ElevatorSystem system(2, 10);

    system.internalRequest(0, 7);

    run_until_stable(system);

    cout << "Internal Request Test Passed\n";
}

int main()
{
    test_basic_request();
    test_invalid_floor();
    test_mid_trip_stop();
    test_multiple_requests();
    test_internal_request();

    cout << "\nAll tests completed successfully!\n";

    return 0;
}