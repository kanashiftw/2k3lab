#include "Address.h"
Address::Address() {
	street = "Не указано";
	number = NULL;
}
Address::Address(std::string _street, int _number) {
	street = _street;
	number = _number;
}
void Address::setAddress() {
	std::cout << "Введите название улицы" << std::endl;
	std::cin >> street;
	std::cout << "Введите номер дома" << std::endl;
	std::cin >> number;
}
void Address::printAdress() {
	std::cout <<"Адрес: " << street << ' ' << number << ' ' << std::endl;
}