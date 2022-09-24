#pragma once
#include <string>;
class IShopFunc {
public:
    virtual void setter() = 0;
    virtual void displayShop() = 0;
    virtual void seriallize(const std::string filename) = 0;
    virtual void deseriallize(const std::string filename) = 0;
};