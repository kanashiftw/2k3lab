#include "Address.h"
Address::Address() {
	street = "�� �������";
	number = NULL;
}
Address::Address(std::string _street, int _number) {
	street = _street;
	number = _number;
}
void Address::setAddress() {
	std::cout << "������� �������� �����" << std::endl;
	std::cin >> street;
	std::cout << "������� ����� ����" << std::endl;
	std::cin >> number;
}
void Address::printAdress() {
	std::cout <<"�����: " << street << ' ' << number << ' ' << std::endl;
}