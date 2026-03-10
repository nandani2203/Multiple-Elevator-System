#ifndef REQUEST_H
#define REQUEST_H

class Request
{
public:

    int floor;          
    bool is_up;         
    bool is_internal;   

    Request(int f, bool up, bool internal = false)
    {
        floor = f;
        is_up = up;
        is_internal = internal;
    }
};

#endif