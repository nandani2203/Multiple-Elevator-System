#include "lobby.h"
#include <iostream>
#include <cmath>
#include <limits>

// Elevator Constructor
Lobby::Elevator::Elevator(int total_floors)
    : curr_floor(0), min_floor(0), max_floor(total_floors - 1), direction("Idle"), is_assigned(false) {}

// Set the elevator's ID
void Lobby::Elevator::set_id(const std::string& id) {
    this->id = id;
}

// Process a request (move the elevator and update state)
void Lobby::Elevator::process_request(int floor, const std::string& new_direction) {
    pushed_floors.push_back(floor);
    curr_floor = floor; // Simulate moving to the requested floor
    direction = new_direction;
    is_assigned = true; // Mark elevator as assigned to the current request
}

// Mark elevator as available after serving the request
void Lobby::Elevator::complete_task() {
    is_assigned = false; // Reset assignment status when task is completed
}

// Check if a floor is within the elevator's range
bool Lobby::Elevator::is_floor_in_range(int floor) const {
    return floor >= min_floor && floor <= max_floor;  // Inclusive of max_floor
}


// Lobby Constructor
Lobby::Lobby(int num_elevators, int floors) : total_floors(floors) {
    int floor_range = floors / num_elevators;

    for (int i = 0; i < num_elevators; ++i) {
        Elevator elevator(floors);
        elevator.set_id("Elevator_" + std::to_string(i + 1));

        // Assign the range for each elevator
        elevator.min_floor = i * floor_range;
        elevator.max_floor = (i == num_elevators - 1) ? floors - 1 : (i + 1) * floor_range - 1;

        std::cout << "Elevator " << elevator.id 
                  << " will serve floors from " << elevator.min_floor 
                  << " to " << elevator.max_floor << std::endl; // Debugging range assignment

        elevators.push_back(elevator);
    }
}

// Lobby Destructor
Lobby::~Lobby() {}

// Generate a new floor request
void Lobby::generate_request(bool direction, int floor) {
    if (floor < 0 || floor >= total_floors) {
        std::cout << "Invalid floor request: " << floor << std::endl;
        return;
    }
    requests.push({direction, floor});
    delegate_requests();
}

void Lobby::delegate_requests() {
    while (!requests.empty()) {
        Request req = requests.front();
        requests.pop();

        std::cout << "Requesting floor " << req.floor << " (Direction: " << (req.direction ? "Up" : "Down") << ")\n";

        bool assigned = false;
        for (auto& elevator : elevators) {
            bool is_in_range = elevator.is_floor_in_range(req.floor);
            std::cout << "Checking elevator " << elevator.id << " for range: " << (is_in_range ? "Yes" : "No") << "\n";
            if (is_in_range && !elevator.is_assigned) {
                elevator.process_request(req.floor, req.direction ? "Up" : "Down");
                std::cout << "Assigned " << elevator.id << " to floor " << req.floor << "\n";
                assigned = true;
                break;
            }
        }

        // If no elevator found
        if (!assigned) {
            // Allow assigning elevators to requests regardless of direction when no elevator is idle
            for (auto& elevator : elevators) {
                bool is_in_range = elevator.is_floor_in_range(req.floor);
                if (is_in_range) {
                    elevator.process_request(req.floor, req.direction ? "Up" : "Down");
                    std::cout << "Assigned " << elevator.id << " to floor " << req.floor << " (force assignment)\n";
                    assigned = true;
                    break;
                }
            }
        }

        if (!assigned) {
            std::cout << "No suitable elevator found for floor " << req.floor << std::endl;
        }
    }
}


// Check if there are no pending requests
bool Lobby::no_requests() const {
    return requests.empty();
}

// Find the best elevator for a request (logic for choosing the elevator)
int Lobby::find_best_elevator(const Request& req) const {
    int best_elevator = -1;
    int min_distance = std::numeric_limits<int>::max();

    for (size_t i = 0; i < elevators.size(); ++i) {
        const Elevator& elevator = elevators[i];

        // Debugging output
        std::cout << "Checking elevator " << elevator.id 
                  << " for floor " << req.floor << " (Direction: " << (req.direction ? "Up" : "Down") << ")\n";
        std::cout << "Elevator " << elevator.id << " is in range: "
                  << (elevator.is_floor_in_range(req.floor) ? "Yes" : "No") << "\n";

        if (!elevator.is_floor_in_range(req.floor)) continue;

        int distance = std::abs(elevator.curr_floor - req.floor);
        if (distance < min_distance && (elevator.direction == "Idle" ||
            (req.direction && elevator.direction == "Up" && elevator.curr_floor <= req.floor) ||
            (!req.direction && elevator.direction == "Down" && elevator.curr_floor >= req.floor))) {
            best_elevator = i;
            min_distance = distance;
        }
    }

    return best_elevator;
}

// Main function to test the lobby system
int main() {
    int total_floors = 10;
    int num_elevators = 3;

    // Create a Lobby with 3 elevators and 10 floors
    Lobby lobby(num_elevators, total_floors);

    // Generate some requests for testing
    lobby.generate_request(true, 3);  // Request to go Up to floor 3
    lobby.generate_request(false, 5); // Request to go Down to floor 5
    lobby.generate_request(true, 7);  // Request to go Up to floor 7

    // Check if there are any remaining requests
    if (lobby.no_requests()) {
        std::cout << "All requests have been processed." << std::endl;
    } else {
        std::cout << "There are still pending requests." << std::endl;
    }

    return 0;
}
