#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "Time.h"
Time::Time() {
	hours = 00;
	minutes = 00;
}
Time::Time(short _hours, short _minutes) {
	hours = _hours;
	minutes = _minutes;
}
std::string Time::printWorkHours(Time a, Time b) {
	std::string str = ("������� �����: " + std::to_string(a.hours) + ':' +  std::to_string(a.minutes) + " - " + std::to_string(b.hours) + ':' + std::to_string(b.minutes));
	return str;
}
void Time::setTime() {
	std::cout << "������� ����"<<std::endl;
	std::cin >> hours;
	std::cout<< "������� ������" << std::endl;
	std::cin >> minutes;
}
