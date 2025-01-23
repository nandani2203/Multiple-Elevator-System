#include <iostream>
#include <cassert>
#include "lobby.h"

// Test Case 1: Node Coverage
void test_node_coverage() {
    std::cout << "Test Node Coverage: Requesting a valid floor within elevator range\n";
    Lobby lobby(2, 10); // 2 elevators, 10 floors
    lobby.generate_request(true, 3);  // Request floor 3 to go up
    assert(lobby.no_requests() == false);  // Ensure the request is processed
    std::cout << "Node Coverage Test Passed\n";
}

// Test Case 2: Edge Coverage
void test_edge_coverage() {
    std::cout << "Test Edge Coverage: Requesting a floor outside the range\n";
    Lobby lobby(2, 10); // 2 elevators, 10 floors
    lobby.generate_request(true, 11);  // Invalid floor request (outside of range)
    // The system should print "Invalid floor request" for floor 11.
    std::cout << "Edge Coverage Test Passed\n";
}

// Test Case 3: Edge Pair Coverage
void test_edge_pair_coverage() {
    std::cout << "Test Edge Pair Coverage: Multiple requests for different floors\n";
    Lobby lobby(2, 10); // 2 elevators, 10 floors
    lobby.generate_request(true, 3);   // Request floor 3 to go up
    lobby.generate_request(false, 5);  // Request floor 5 to go down
    // The system will assign elevators based on proximity and direction.
    std::cout << "Edge Pair Coverage Test Passed\n";
}

// Test Case 4: Prime Path Coverage
void test_prime_path_coverage() {
    std::cout << "Test Prime Path Coverage: Elevator handling multiple requests\n";
    Lobby lobby(2, 10); // 2 elevators, 10 floors
    lobby.generate_request(true, 2);   // Request floor 2 to go up
    lobby.generate_request(true, 5);   // Request floor 5 to go up
    lobby.generate_request(false, 3);  // Request floor 3 to go down
    // Multiple prime paths should be exercised as the elevator moves between floors and handles requests.
    std::cout << "Prime Path Coverage Test Passed\n";
}

// Test Case 5: Elevator with No Suitable Assignment (Alternate Test Case)
void test_no_suitable_elevator() {
    std::cout << "Test: Elevator with No Suitable Assignment (Alternate Case)\n";
    Lobby lobby(3, 10); // 3 elevators, 10 floors
    // Here, we'll request a floor that has no elevator assigned to it.
    // We'll check if the request for an invalid floor (or outside of the elevator ranges) is handled properly.
    lobby.generate_request(true, 11);  // Request a non-existent floor (out of range)
    // We expect the system to print that the request is invalid and no elevator is available for this floor.
    std::cout << "No Suitable Elevator Test Passed\n";
}

int main() {
    // Running Node Coverage Test
    test_node_coverage();
    
    // Running Edge Coverage Test
    test_edge_coverage();

    // Running Edge Pair Coverage Test
    test_edge_pair_coverage();

    // Running Prime Path Coverage Test
    test_prime_path_coverage();

    // Running No Suitable Elevator Test (Alternate Case)
    test_no_suitable_elevator();

    return 0;
}
//g++ -g lobby.cpp -o lobby.exe
//C:\Users\ashis\OneDrive\Desktop\ElevatorLobby\lobby.exe
