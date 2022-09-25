#pragma once
#include <string>
class ILoggable {
public:
    virtual void logcout(std::string text) = 0;
    virtual void logtofile(std::string text, std::string filename) = 0;
};