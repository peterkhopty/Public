#include "../Solver/Money.h"
#include "iostream"
using namespace rut::cip::money;

int main()
{
	setlocale(LC_ALL, "RU");
	try
	{
		rut::cip::money::Money money{ 5, 6.76 };
		auto actual = money.ToString();

		std::cout << "Введите первую денежную  сумму: " << std::endl;
		Money money1;
		std::cin >> money1;
		std::cout << money1;
		std::cout << "Введите вторую денежную сумму: " << std::endl;
		Money money2;
		std::cin >> money2;
		std::cout << money2;

		std::cout << "Сумма двух объектов класса Деньги: " << std::endl;
		Money sum = money1 + money2;
		std::cout << sum;

		std::cout << "Разность двух объектов класса Деньги: " << std::endl;
		Money difference = money1 - money2;
		std::cout << difference;

		std::cout << "Частное двух объектов класса Деньги: " << std::endl;
		Money quotient = money1 / money2;
		std::cout << quotient;

		std::cout << "Произведение двух объектов класса Деньги: " << std::endl;
		Money composition = money1 * money2;
		std::cout << composition;
	}
	catch (std::logic_error& e)
	{
		std::cerr << "Ошибка " << e.what();
	}
	return EXIT_SUCCESS;
}