# Multiple Elevator System Simulation (C++)

## Problem Statement

Modern buildings often contain multiple elevators that must efficiently respond to passenger requests from different floors.  
The challenge is to design a control system that decides:

1. Which elevator should respond to a request
2. How elevators should move between floors
3. How to minimize passenger wait time
4. How to efficiently manage multiple elevators simultaneously

This project implements a Multiple Elevator System Simulator in C++ that models how elevators handle internal and external requests in a building.

The system uses a simple scheduling heuristic to assign requests to elevators based on:

1. Distance to the requested floor
2. Current direction of the elevator
3. Whether the elevator can pick up the request while moving

The goal is to simulate how real elevator systems operate and demonstrate concepts such as object-oriented design, scheduling algorithms, and system simulation.

# Features

## 1. Multiple Elevator Support
The system supports multiple elevators operating in the same building.

Each elevator operates independently but is coordinated by the ElevatorSystem controller.

## 2. External Floor Requests

Passengers waiting on a floor can press:

1. UP button
2. DOWN button

The system decides which elevator should respond.

## 3. Internal Elevator Requests

Passengers inside an elevator can select their destination floor.

The elevator adds that floor to its stop list.


## 4. Intelligent Elevator Scheduling

The system assigns elevators using a score-based heuristic that considers:

1. Distance to the requested floor
2. Elevator direction
3. Whether the elevator can pick up the request along its path

This helps reduce unnecessary direction changes and improves efficiency.

## 5. Real-Time Simulation

The system runs a step-based simulation where elevators move one floor per step.

Each step includes:

1. Assign pending requests
2. Move elevators
3. Print system state


## 6. Dynamic Requests During Simulation

New requests can be generated while the simulation is running.

# System Architecture

The system is built using modular object-oriented design.
```
Multiple Elevator System
│
├── ElevatorSystem → Central controller
│
├── Elevator → Represents an individual elevator
│
├── Request → Represents a floor request
│
└── Simulator → Prints system state
```

# Project Structure
```
Multiple-Elevator-System
│
├── include
│ ├── elevator.h
│ ├── elevator_system.h
│ ├── request.h
│ └── simulator.h
│
├── src
│ ├── elevator.cpp
│ ├── elevator_system.cpp
│ └── simulator.cpp
│
├── test
│ └── test.cpp
│
├── main.cpp
└── README.md
```

# How to Run the Project

## 1. Compile the Project

From the project root directory:

bash
```
g++ main.cpp src/*.cpp -I include -o elevator_sim
```
## 2. Run the Simulation
bash
```
./elevator_sim
```
On Windows
```

elevator_sim.exe
```
## 3. Run Unit Tests

1. Compile tests:
```
g++ test/test.cpp src/*.cpp -I include -o test
```
2. Run tests:
```
./test
```

# Key Concepts Demonstrated

1. Object-Oriented Design
2. Resource Management in C++
3. Scheduling Algorithms
4. System Simulation
5. Modular Architecture
