#pragma once

struct systems
{
    int dangerLevel;
    int supplies;
    int x, y;
    int systemID;
    bool explored;
    bool current = false;
    bool objective;
};
