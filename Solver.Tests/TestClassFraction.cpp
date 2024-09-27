#include "CppUnitTest.h"
#include "../Solver/Fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestClassFraction
{
	TEST_CLASS(TestClassFraction)
	{
	public:
		
		TEST_METHOD(ToString_ZeroData_Success)
		{
			rut::cip::money::Fraction fraction{};
			std::string expected{"0, 0"};
			auto actual = fraction.ToString();
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor1_SameFraction_Success)
		{
			rut::cip::money::Fraction fraction{ 5, 6 };
			std::string expected{ "5, 6" };
			auto actual = fraction.ToString();
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor2_SameFraction_Success)
		{
			rut::cip::money::Fraction fraction{ 0.1 };
			std::string expected{ "1, 10" };
			auto actual = fraction.ToString();
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor3_ZeroData_Success)
		{
			rut::cip::money::Fraction fraction{};
			std::string expected{ "0, 0" };
			auto actual = fraction.ToString();
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AbsFraction_DifferentFraction_True)
		{
			rut::cip::money::Fraction fraction{ -5, 7 };
			rut::cip::money::Fraction expected{ 5, 7 };
			Assert::IsTrue(fraction.Abs() == expected);
		}

		TEST_METHOD(OperatorDouble_FractionAndDouble_True)
		{
			rut::cip::money::Fraction fraction{ 1, 2 };
			auto expected = 0.5;
			auto actual = double(fraction);
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(SelectionFractionalPart_DifferentFraction_True)
		{
			rut::cip::money::Fraction expected{ 1, 2 };
			rut::cip::money::Fraction fraction{ 3, 2 };
			rut::cip::money::Fraction actual{};
			actual = fraction.selectionFractionalPart();
			Assert::IsTrue(expected == actual);
		}

		TEST_METHOD(AddingWholeToFraction_FractionAndInt_True)
		{
			int whole = 5;
			rut::cip::money::Fraction actual{ 3, 2 };
			rut::cip::money::Fraction expected{ 13, 2 };
			Assert::IsTrue(expected == actual.addingWholeToFraction(whole));
		}

		TEST_METHOD(OperatorSum_DifferentFraction_True)
		{
			rut::cip::money::Fraction fraction1{ -5, 7 };
			rut::cip::money::Fraction fraction2{ 7, 8 };
			rut::cip::money::Fraction expected{ 9, 56 };
			Assert::IsTrue(fraction1 + fraction2 == expected);
		}

		TEST_METHOD(OperatorSum_DifferentFraction_False)
		{
			rut::cip::money::Fraction fraction1{ -5, 7 };
			rut::cip::money::Fraction fraction2{ 7, 8 };
			rut::cip::money::Fraction expected{ 1, 56 };
			Assert::IsFalse(fraction1 + fraction2 == expected);
		}

		TEST_METHOD(OperatorDifference_DifferentFraction_True)
		{
			rut::cip::money::Fraction fraction1{ -9, 2 };
			rut::cip::money::Fraction fraction2{ 5, 2 };
			rut::cip::money::Fraction expected{ -7, 1 };
			Assert::IsTrue(fraction1 - fraction2 == expected);
		}

		TEST_METHOD(OperatorDifference_DifferentFraction_False)
		{
			rut::cip::money::Fraction fraction1{ -9, 2 };
			rut::cip::money::Fraction fraction2{ 5, 2 };
			rut::cip::money::Fraction expected{ 7, 1 };
			Assert::IsFalse(fraction1 - fraction2 == expected);
		}

		TEST_METHOD(OperatorQuotient_DifferentFraction_True)
		{
			rut::cip::money::Fraction fraction1{ -9, 2 };
			rut::cip::money::Fraction fraction2{ -5, 2 };
			rut::cip::money::Fraction expected{ 9, 5 };
			Assert::IsTrue(fraction1 / fraction2 == expected);
		}

		TEST_METHOD(OperatorQuotient_DifferentFraction_False)
		{
			rut::cip::money::Fraction fraction1{ -9, 2 };
			rut::cip::money::Fraction fraction2{ -5, 2 };
			rut::cip::money::Fraction expected{ -9, 5 };
			Assert::IsFalse(fraction1 / fraction2 == expected);
		}

		TEST_METHOD(OperatorComposition_DifferentFraction_True)
		{
			rut::cip::money::Fraction fraction1{ -9, 2 };
			rut::cip::money::Fraction fraction2{ 5, 2 };
			rut::cip::money::Fraction expected{ -45, 4 };
			Assert::IsTrue(fraction1 * fraction2 == expected);
		}

		TEST_METHOD(OperatorComposition_DifferentFraction_False)
		{
			rut::cip::money::Fraction fraction1{ -9, 2 };
			rut::cip::money::Fraction fraction2{ 5, 2 };
			rut::cip::money::Fraction expected{ 45, 4 };
			Assert::IsFalse(fraction1 * fraction2 == expected);
		}
		TEST_METHOD(OperatorEqual_SameFraction_True)
		{
			rut::cip::money::Fraction fraction1{ 2, 2 };
			rut::cip::money::Fraction fraction2{ 2, 2 };
			Assert::IsTrue(fraction1 == fraction2);
		}

		TEST_METHOD(OperatorEqual_DifferentFraction_False)
		{
			rut::cip::money::Fraction fraction1{ 9, 2 };
			rut::cip::money::Fraction fraction2{ 5, 2 };
			Assert::IsFalse(fraction1 == fraction2);
		}

		TEST_METHOD(OperatorNoEqual_SameFraction_False)
		{
			rut::cip::money::Fraction fraction1{ 2, 2 };
			rut::cip::money::Fraction fraction2{ 2, 2 };
			Assert::IsFalse(fraction1 != fraction2);
		}

		TEST_METHOD(OperatorNoEqual_DifferentFraction_True)
		{
			rut::cip::money::Fraction fraction1{ 9, 2 };
			rut::cip::money::Fraction fraction2{ 5, 2 };
			Assert::IsTrue(fraction1 != fraction2);
		}
	};
}

	