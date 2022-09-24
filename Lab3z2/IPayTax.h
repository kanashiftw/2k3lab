#pragma once
const double LAND = 0.15;
const double NDFL = 0.13;
const double NDS = 0.18;
class IPayTax {
public:
	virtual void payTax() = 0;
};