#include "Money.h"
using namespace rut::cip::money;

rut::cip::money::Money::Money(int rubles, double coins)
	:rubles{ Sign(rubles) * Sign(coins) * (std::abs(rubles) + std::abs(static_cast<int>(coins))) },
	coins{ Fraction(SignCoins(rubles, coins)) * Fraction(coins).selectionFractionalPart().Abs() }
{
}

rut::cip::money::Money::Money(double realNumber)
	: rubles{ static_cast<int>(realNumber) }, coins{ Fraction(SignCoins(realNumber)) * Fraction(realNumber).selectionFractionalPart().Abs() }
{

}

rut::cip::money::Money::Money(Fraction fraction)
	: rubles{ static_cast<int>(double(fraction)) }, coins{ Fraction(SignCoins(double(fraction))) * fraction.selectionFractionalPart().Abs() }
{
}

rut::cip::money::Money::Money()
	: rubles{ 0 }, coins{ 0 }
{
}

int rut::cip::money::Money::Sign(int meaning)
{
	return (meaning >= 0) ? (1) : (-1);
}

int rut::cip::money::Money::Sign(double meaning)
{
	return (meaning >= 0) ? (1) : (-1);
}

int rut::cip::money::Money::SignCoins(int rubles, double coins)
{
	return ((std::abs(rubles) + std::abs(static_cast<int>(coins))) <= 0) ? (Sign(rubles) * Sign(coins)) : (1);
}

int rut::cip::money::Money::SignCoins(double coins)
{
	return (static_cast<int>(std::abs(coins)) == 0) ? (Sign(coins)) : (1);
}

Money rut::cip::money::operator+(Money& lha, Money& rha)
{
	auto coins = lha.coins.addingWholeToFraction(lha.rubles) + rha.coins.addingWholeToFraction(rha.rubles);
	return Money(coins);
}

Money rut::cip::money::operator-(Money& lha, Money& rha)
{
	auto coins = lha.coins.addingWholeToFraction(lha.rubles) - rha.coins.addingWholeToFraction(rha.rubles);
	return Money(coins);
}

Money rut::cip::money::operator*(Money& lha, Money& rha)
{
	auto coins = lha.coins.addingWholeToFraction(lha.rubles) * rha.coins.addingWholeToFraction(rha.rubles);
	return Money(coins);
}

Money rut::cip::money::operator/(Money& lha, Money& rha)
{
	auto coins = lha.coins.addingWholeToFraction(lha.rubles) / rha.coins.addingWholeToFraction(rha.rubles);
	return Money(coins);
}

std::wstring rut::cip::money::ToString(Money& money)
{
	std::wstringstream buffer{};
	buffer << money.rubles << L" руб. " << static_cast<int>(double(money.coins) * 100) << L" коп.";
	return buffer.str();
}

std::string rut::cip::money::Money::ToString()
{
	std::stringstream buffer{};
	buffer << this->rubles << " руб. " << static_cast<int>(double(this->coins) * 100) << " коп.";
	return buffer.str();
}

std::ostream& rut::cip::money::operator<<(std::ostream& out, Money& money)
{
	return out << money.ToString();
}

std::istream& rut::cip::money::operator>>(std::istream& in, Money& money)
{
	double firstInputNumber = 0.0;
	in >> firstInputNumber;
	if (std::fmod(std::abs(firstInputNumber), 1) > 0)
	{
		Money moneyOfRealNumber(firstInputNumber);
		money.rubles = moneyOfRealNumber.rubles;
		money.coins = moneyOfRealNumber.coins;
		return in;
	}
	double secondInputNumber = 0.0;
	in >> secondInputNumber;
	if (std::fmod(std::abs(secondInputNumber), 1) > 0)
	{
		Money moneyOfIntAndRealNumber(static_cast<int>(firstInputNumber), secondInputNumber);
		money.rubles = moneyOfIntAndRealNumber.rubles;
		money.coins = moneyOfIntAndRealNumber.coins;
		return in;
	}
	Money moneyOfFraction(Fraction(static_cast<int>(firstInputNumber), static_cast<int>(secondInputNumber)));
	money.rubles = moneyOfFraction.rubles;
	money.coins = moneyOfFraction.coins;
	return in;
}

bool rut::cip::money::Money::operator==(const Money& rha)
{
	return (rubles == rha.rubles && coins == rha.coins);
}

bool rut::cip::money::Money::operator!=(const Money& rha)
{
	return (rubles != rha.rubles && coins != rha.coins);
}