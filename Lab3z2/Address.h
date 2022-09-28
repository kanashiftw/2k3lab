#pragma once
#include <string>
#include <iostream>
class Address {
public:
    std::string street;
    int number;
    Address();
    Address(std::string _street, int _numbers);
    void setAddress();
    void printAdress();
   
};