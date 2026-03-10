#ifndef REQUEST_H
#define REQUEST_H

class Request
{
public:

    int floor;          // Requested floor
    bool is_up;         // Direction (true = UP, false = DOWN)
    bool is_internal;   // Internal elevator request

    /*
    Constructor
    */
    Request(int f, bool up, bool internal = false)
    {
        floor = f;
        is_up = up;
        is_internal = internal;
    }
};

#endif