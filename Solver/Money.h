#include "../Solver/Fraction.h"
#include "iostream"
#include "sstream"
#pragma once

namespace rut::cip::money
{
	/**
	* @brief Определение операций для класса Money.
	*/
	class Money
	{
	private:

		/**
		* @brief Рубли.
		*/
		int rubles;

		/**
		* @brief Копейки.
		*/
		Fraction coins;

		/**
        * @brief Выводит 1, если целое число положительное, и -1,если целое число отрицательное.
        * @param meaning Целое число.
        */
		int Sign(int meaning);

		/**
        * @brief Выводит 1, если вещественное число положительное, и -1,если вещественное число отрицательное.
        * @param realNumber Вещественное число.
        */
		int Sign(double meaning);

		/**
        * @brief Выводит знак для монет, рубль равен нулю.
		* @param rubles Рубли.
		* @param coins Копейки.
        */
		int SignCoins(int rubles, double coins);

		/**
        * @brief Выводит знак для монет, рубль равен нулю.
        * @param coins Копейки.
        */
		int SignCoins(double coins);

	public:

		/**
		* @brief Создает экземпляр класса "Money"
		* @param rubles Рубли.
		* @param coins Копейки.
		*/
		Money(int rubles, double coins);

		/**
		* @brief Создает экземпляр класса "Money"
		* @param realNumber Вещественное число.
		*/
		explicit Money(double realNumber);

		/**
        * @brief Создает экземпляр класса "Money"
        * @param fraction Экземпляр класса "Fraction".
        */
		explicit Money(Fraction fraction);

		/**
        * @brief Создает экземпляр класса "Money".
        */
		Money();

		/**
        * @brief Складывает два экземпляр класса "Money".
        * @param lha первый экземпляр класса "Money".
        * @param rha второй экземпляр класса "Money".
        */
		friend Money operator+(Money& lha, Money& rha);

		/**
        * @brief Даёт разность двух экземпляров класса "Money".
        * @param lha первый экземпляр класса "Money".
        * @param rha второй экземпляр класса "Money".
        */
		friend Money operator-(Money& lha, Money& rha);

		/**
        * @brief Делит два экземпляра класса "Money".
        * @param lha первый экземпляр класса "Money".
        * @param rha второй экземпляр класса "Money".
        */
		friend Money operator/(Money& lha, Money& rha);

		/**
        * @brief Умножает два экземпляра класса "Money".
        * @param lha первый экземпляр класса "Money".
        * @param rha второй экземпляр класса "Money".
        */
		friend Money operator*(Money& lha, Money& rha);

		/**
        * @brief Выводит экземпляр класса "Money".
        * @param money Экземпляр класса "Money".
        */
		friend std::wstring ToString(Money& money);

		/**
        * @brief Выводит экземпляр класса "Money".
        */
		std::string ToString();

		/**
        * @brief Выводит экземпляр класса "Money".
		* @param money Экземпляр класса "Money".
        */
		friend std::ostream& operator<<(std::ostream& out, Money& money);

		/**
        * @brief Ввод экземпляра класса "Money".
        * @param money Экземпляр класса "Money".
        */
		friend std::istream& operator>>(std::istream& in, Money& money);

		/**
        * @brief Сравнивает на равенство два экземпляра класса "Money".
        * @param rha Экземпляр класса "Money".
        */
		bool operator==(const Money& rha);

		/**
        * @brief Сравнивает на неравенство два экземпляра класса "Money".
        * @param rha Экземпляр класса "Money".
        */
		bool operator!=(const Money& rha);
	};
}