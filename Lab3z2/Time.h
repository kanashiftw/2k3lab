#pragma once
#include <string>
#include <iostream>
class Time {

public:
    short hours;
    short minutes;
    Time();
    Time(short _hours, short _minutes);
    std::string printWorkHours(Time a, Time b);
    void setTime();
};