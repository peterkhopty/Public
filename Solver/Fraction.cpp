#include "Fraction.h"

namespace rut::cip::money
{
	rut::cip::money::Fraction::Fraction(int numerator, int denominator)
		:numerator{ (numerator / LargestCommonDivisor(numerator, denominator)) }, denominator{ (denominator / LargestCommonDivisor(numerator, denominator)) }
	{
		if (denominator < 0)
		{
			throw std::invalid_argument("Знаменатель должен быть неотрицательным");
		}

		if (denominator == 0)
		{
			throw std::invalid_argument("Знаменатель не должен быть равен нулю");
		}
	}

	rut::cip::money::Fraction::Fraction(double realNumber)
		:numerator{ Sign(realNumber) * GetNumerator(realNumber) / LargestCommonDivisor(GetNumerator(realNumber), GetDenominator(realNumber)) },
		denominator{ GetDenominator(realNumber) / LargestCommonDivisor(GetNumerator(realNumber), GetDenominator(realNumber)) }
	{
	}

	Fraction::Fraction()
		:numerator{ 0 }, denominator{ 0 }
	{
	}

	Fraction rut::cip::money::Fraction::Abs()
	{
		return Fraction(std::abs(numerator), denominator);
	}

	int Fraction::LargestCommonDivisor(int numerator, int denominator)
	{
		int lha = std::abs(numerator);
		int rha = denominator;
		int divider = 1;
		if (lha != rha)
		{
			while (lha != 0 and rha != 0)
			{
				if (lha > rha)
				{
					lha %= rha;
				}
				else
				{
					rha %= lha;
				}
			}
			divider = lha + rha;
		}
		else
		{
			divider = lha;
		}
		return divider;
	}

	rut::cip::money::Fraction::operator double()
	{
		return this->numerator * 1.0 / this->denominator;
	}

	int Fraction::Sign()
	{
		return (this->numerator >= 0) ? (1) : (-1);
	}

	int Fraction::Sign(int meaning)
	{
		return (meaning >= 0) ? (1) : (-1);
	}

	Fraction Fraction::selectionFractionalPart()
	{
		int absNumerator = std::abs(numerator);
		while (absNumerator >= denominator)
		{
			absNumerator -= denominator;
		}
		absNumerator *= Sign(numerator);
		return Fraction(absNumerator, denominator);
	}

	Fraction Fraction::addingWholeToFraction(int whole)
	{
		auto newNumerator = Sign(whole) * (std::abs(whole * denominator) + numerator);
		return Fraction(newNumerator, denominator);
	}

	int rut::cip::money::Fraction::GetNumerator(double realNumber)
	{
		return static_cast<int>(std::abs(realNumber) * 100);
	}

	int rut::cip::money::Fraction::GetDenominator(double realNumber)
	{
		return 100;
	}

	int rut::cip::money::Fraction::Sign(double realNumber)
	{
		return (realNumber >= 0) ? (1) : (-1);
	}

	void rut::cip::money::Fraction::CheckRealNumberNotBeZero(double realNumber)
	{
		if (std::abs(realNumber) <= std::numeric_limits<double>::epsilon())
		{
			throw std::invalid_argument("Вещественное число не должно быть равно нулю");
		}
	}

	Fraction rut::cip::money::operator+(const Fraction& lha, const Fraction& rha)
	{
		auto numerator = lha.numerator * rha.denominator + rha.numerator * lha.denominator;
		auto denominator = lha.denominator * rha.denominator;
		return Fraction(numerator, denominator);
	}

	Fraction rut::cip::money::operator-(const Fraction& lha, const Fraction& rha)
    {
		auto numerator = lha.numerator * rha.denominator - rha.numerator * lha.denominator;
		auto denominator = lha.denominator * rha.denominator;
		return Fraction(numerator, denominator);
	}

	Fraction rut::cip::money::operator*(const Fraction& lha, const Fraction& rha)
	{
		auto numerator = lha.numerator * rha.numerator;
		auto denominator = lha.denominator * rha.denominator;
		return Fraction(numerator, denominator);
	}

	Fraction rut::cip::money::operator/(const Fraction& lha, const Fraction& rha)
	{
		auto numerator = lha.numerator * rha.denominator * rha.numerator / std::abs(rha.numerator);
		auto denominator = std::abs(rha.numerator) * lha.denominator;
		return Fraction(numerator, denominator);
	}

	std::wstring rut::cip::money::ToString(const Fraction& fraction)
	{
		std::wstringstream buffer{};
		buffer << fraction.numerator << L", " << fraction.denominator;
		return buffer.str();
	}

	std::string Fraction::ToString() const
	{
		std::stringstream buffer{};
		buffer << this->numerator << ", " << this->denominator;
		return buffer.str();
	}

	std::ostream& rut::cip::money::operator<<(std::ostream& out, Fraction& fraction)
	{
		return out << fraction.ToString();
	}

	std::istream& rut::cip::money::operator>>(std::istream& in, Fraction& fraction)
	{
		double firstInputNumber = 0.0;
		in >> firstInputNumber;
		if (std::fmod(std::abs(firstInputNumber), 1) > 0)
		{
			Fraction fractionOfRealNumber(firstInputNumber);
			fraction.numerator = fractionOfRealNumber.numerator;
			fraction.denominator = fractionOfRealNumber.denominator;
			return in;
		}
		else
		{
			int secondInputNumber;
			in >> secondInputNumber;
			Fraction fraction(static_cast<int>(firstInputNumber), secondInputNumber);
			fraction.numerator = fraction.numerator;
			fraction.denominator = fraction.denominator;
			return in;
		}
	}

	bool Fraction::operator==(const Fraction& rha)
	{
		return (numerator == rha.numerator && denominator == rha.denominator);
	}

	bool Fraction::operator!=(const Fraction& rha)
	{
		return (numerator != rha.numerator || denominator != rha.denominator);
	}
}