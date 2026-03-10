#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include "elevator.h"

using namespace std;

class Simulator
{
public:

    static void printSystem(const vector<Elevator>& elevators);
};

#endif