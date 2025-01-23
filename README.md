# Multiple-Elevator-System
 A multi-elevator system in C++ with optimized scheduling for efficient floor coordination
Explanation of lobby.h and lobby.cpp
1. lobby.h (Header File)
The lobby.h file contains the declarations of the classes and functions used in the elevator system. It defines the structure and functionality of the Lobby and Elevator classes and outlines the interfaces that will be implemented in lobby.cpp.
Key Components:
Lobby Class: Represents the main control system for managing the elevators and requests. It contains a list of elevators, manages requests, and delegates tasks to available elevators.


Elevator Class: Represents an individual elevator and contains information like the elevator's current floor, range of floors it serves, its direction, and its assignment status. This class handles the logic for processing floor requests and completing tasks.


Request Struct: A struct to hold a request with information such as the floor number and the direction (up or down) of the request.


Key Functions and Methods:
Lobby Constructor: Initializes the number of elevators and their floor ranges. For each elevator, the constructor sets a unique ID and assigns floors it will serve.
generate_request: Generates a new request for a given floor and direction, then delegates it to the available elevator.
delegate_requests: Iterates through the queue of requests and assigns the appropriate elevator based on the current floor and direction.
find_best_elevator: Finds the best elevator for a request by considering the distance and direction of movement.
no_requests: Checks if all the requests have been processed and there are no pending requests.
The header file defines the structure and behavior of the system but does not include the actual implementations of the functions.
2. lobby.cpp (Implementation File)
The lobby.cpp file contains the actual implementations of the functions and methods declared in lobby.h. It is responsible for the logic and flow control of the elevator system.
Key Components:
Elevator Constructor (Elevator::Elevator): This constructor initializes the elevator's state, including its current floor, minimum and maximum service floors, direction (idle initially), and assignment status.
process_request: Handles the request for an elevator. When a request is made, the elevator will update its current floor and direction, and it will mark itself as "assigned" to handle the request.
complete_task: Resets the elevator's status to "idle" once it completes its assigned task.
is_floor_in_range: Checks if the requested floor is within the service range of the elevator.
Lobby Class Implementation:
Lobby::Lobby: The constructor initializes the system by creating a specified number of elevators and assigning each one to a range of floors based on the total number of floors. It sets the range for each elevator and outputs the assignment.


generate_request: This function is used to create a new request. It first checks if the floor is valid. If valid, the request is added to the queue and delegated for processing.


delegate_requests: This function processes all the requests in the queue. It checks each elevator to see if it can serve the requested floor. If an elevator is available and within range, it processes the request and marks the elevator as assigned. If no elevator is available, a message is displayed.


find_best_elevator: This function finds the elevator that is best suited to serve the current request. It does this by calculating the distance between the current floor of each elevator and the requested floor. The elevator with the shortest distance is selected, and additional checks are done to ensure it is moving in the right direction (up or down).


no_requests: This function checks if all requests have been processed by looking at the request queue.


Logic Flow:
Elevator Assignment: When a request is generated, the system checks which elevator can serve the floor by comparing the requested floor with the service range of each elevator. If an elevator is available and within range, it is assigned the task.


Request Handling: If an elevator is already assigned to another task, it is skipped for that request. If no suitable elevator is found for a floor, the system moves to the next request.


Completion: Once a task is completed, the elevator resets its status to "idle," and the system moves on to the next request.


Main Function (main in lobby.cpp):
In the main function, the system is initialized with a set number of elevators and floors. A few test requests are generated (to floors 3, 5, and 7).
The system processes these requests by delegating them to the available elevators.
After processing all requests, it checks if there are any remaining pending requests.

Summary of Workflow:
Initialization: When the program starts, the Lobby object is created with the required number of elevators and floors. Each elevator is assigned a range of floors it will serve.


Request Generation: Requests are generated for different floors, with specified directions (up or down). These requests are added to the queue for processing.


Request Delegation: The system checks which elevator is in range to serve the request and delegates the task. If no elevator is available, it moves to the next request.


Elevator Assignment: The best available elevator is chosen based on the current floor, direction, and distance to the requested floor.


Completion: After all requests are processed, the system checks if there are any remaining requests.



Conclusion:
lobby.h serves as the declaration file where the structure of the elevator system is defined.
lobby.cpp implements the logic for managing the elevators, processing requests, and assigning elevators to tasks.
The system uses a queue to manage requests and checks for the availability of elevators to serve them based on their floor range and direction.

