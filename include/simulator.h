#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <memory>
#include "elevator.h"

using namespace std;

class Simulator
{
public:

    static void printSystem(const vector<unique_ptr<Elevator>>& elevators);
};

#endif