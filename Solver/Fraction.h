#include "iostream"
#include "sstream"
#include <iomanip>
#pragma once

namespace rut::cip::money
{
    /**
    * @brief Определение операций для класса Node.
    */
    class Fraction final
    {
    private:

        /**
        * @brief Числитель.
        */
        int numerator;

        /**
        * @brief Знаменатель.
        */
        int denominator;

        /**
        * @brief Выводит числитель из вещественного числа.
        * @param realNumber Вещественное число.
        */
        int GetNumerator(double realNumber);

        /**
        * @brief Выводит знаменатель из вещественного числа.
        * @param realNumber Вещественное число.
        */
        int GetDenominator(double realNumber);

        /**
        * @brief Выводит 1, если вещественное число положительное, и -1,если вещественное число отрицательное.
        * @param realNumber Вещественное число.
        */
        int Sign(double realNumber);

        /**
        * @brief Выдаёт ошибку, если вещественное число равно нулю.
        * @param realNumber Вещественное число.
        */
        static void CheckRealNumberNotBeZero(double realNumber);

        /**
        * @brief Выводит 1, если числитель положительный, и -1,если числитель отрицательный.
        */
        int Sign();

        /**
        * @brief Выводит 1, если целое число положительное, и -1,если целое число отрицательное.
        * @param meaning Целое число.
        */
        int Sign(int meaning);

        /**
        * @brief Выводит наибольший общий делитель числителя и знаменателя.
        * @param numerator Числитель.
        * @param denominator Знаменатель.
        */
        int LargestCommonDivisor(int numerator, int denominator);

    public:

        /**
        * @brief Создает экземпляр класса "Fraction".
        * @param numerator Числитель.
        * @param denominator Знаменатель.
        */
        Fraction(int numerator, int denominator);

        /**
        * @brief Создает экземпляр класса "Fraction".
        * @param realNumber Вещественное число.
        */
        explicit Fraction(double realNumber);

        /**
        * @brief Создает экземпляр класса "Fraction".
        */
        Fraction();

        /**
        * @brief Класс "Fraction" в модуле.
        */
        Fraction Abs();

        /**
        * @brief Переопределяет класс "Fraction" в double.
        */
        operator double();

        /**
        * @brief Добавляет к дроби целую часть.
        * @param whole Целое число.
        */
        Fraction addingWholeToFraction(int whole);

        /**
        * @brief Убавляет из дроби целую часть.
        */
        Fraction selectionFractionalPart();

        /**
        * @brief Складывает два экземпляр класса "Fraction".
        * @param lha первый экземпляр класса "Fraction".
        * @param rha второй экземпляр класса "Fraction".
        */
        friend Fraction operator+(const Fraction& lha, const Fraction& rha);

        /**
        * @brief Даёт разность двух экземпляров класса "Fraction".
        * @param lha первый экземпляр класса "Fraction".
        * @param rha второй экземпляр класса "Fraction".
        */
        friend Fraction operator-(const Fraction& lha, const Fraction& rha);

        /**
        * @brief Делит два экземпляра класса "Fraction".
        * @param lha первый экземпляр класса "Fraction".
        * @param rha второй экземпляр класса "Fraction".
        */
        friend Fraction operator/(const Fraction& lha, const Fraction& rha);

        /**
        * @brief Умножает два экземпляра класса "Fraction".
        * @param lha первый экземпляр класса "Fraction".
        * @param rha второй экземпляр класса "Fraction".
        */
        friend Fraction operator*(const Fraction& lha, const Fraction& rha);

        /**
        * @brief Выводит экземпляр класса "Fraction".
        * @param fraction Экземпляр класса "Fraction".
        */
        friend std::wstring ToString(const Fraction& fraction);

        /**
        * @brief Выводит экземпляр класса "Fraction".
        */
        std::string ToString() const;

        /**
        * @brief Выводит экземпляр класса "Fraction".
        * @param fraction Экземпляр класса "Fraction".
        */
        friend std::ostream& operator<<(std::ostream& out, Fraction& fraction);

        /**
        * @brief Ввод экземпляра класса "Fraction".
        * @param fraction Экземпляр класса "Fraction".
        */
        friend std::istream& operator>>(std::istream& in, Fraction& fraction);

        /**
        * @brief Сравнивает на равенство два экземпляра класса "Fraction".
        * @param rha Экземпляр класса "Fraction".
        */
        bool operator==(const Fraction& rha);

        /**
        * @brief Сравнивает на неравенство два экземпляра класса "Fraction".
        * @param rha Экземпляр класса "Fraction".
        */
        bool operator!=(const Fraction& rha);
    };
};