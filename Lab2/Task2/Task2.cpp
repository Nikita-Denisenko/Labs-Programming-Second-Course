#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    static int count;

public:
    Fraction(int numerator = 0, int denominator = 1)
        : numerator(numerator), denominator(denominator)
    {
        if (denominator == 0)
            this->denominator = 1;

        reduce();
        ++count;
    }

    Fraction(const Fraction& other)
        : numerator(other.numerator),
        denominator(other.denominator)
    {
        ++count;
    }

    ~Fraction()
    {
        --count;
    }

    static int gcd(int n1, int n2)
    {
        n1 = abs(n1);
        n2 = abs(n2);

        while (n2 != 0)
        {
            int temp = n1 % n2;
            n1 = n2;
            n2 = temp;
        }

        return n1;
    }

    void reduce()
    {
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }

        int divisor = gcd(numerator, denominator);

        if (divisor != 0)
        {
            numerator /= divisor;
            denominator /= divisor;
        }
    }

    Fraction operator+(const Fraction& other) const
    {
        return Fraction(
            numerator * other.denominator +
            other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction operator-(const Fraction& other) const
    {
        return Fraction(
            numerator * other.denominator -
            other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction operator*(const Fraction& other) const
    {
        return Fraction(
            numerator * other.numerator,
            denominator * other.denominator
        );
    }

    Fraction operator/(const Fraction& other) const
    {
        return Fraction(
            numerator * other.denominator,
            denominator * other.numerator
        );
    }

    void print() const
    {
        cout << numerator << '/' << denominator;
    }

    static int getCount()
    {
        return count;
    }

    static void printAsFraction(double dec_fraction)
    {
        const int precision = 1000000;

        int numerator = static_cast<int>(
            round(dec_fraction * precision)
            );

        Fraction fraction(numerator, precision);

        fraction.print();
    }

    static void printAsFraction(char* dec_fraction)
    {
        string value(dec_fraction);

        size_t dotPosition = value.find('.');

        if (dotPosition == string::npos)
        {
            cout << value << "/1";
            return;
        }

        int digitsAfterDot =
            static_cast<int>(value.length() - dotPosition - 1);

        int denominator = 1;

        for (int i = 0; i < digitsAfterDot; ++i)
            denominator *= 10;

        string integerPart = value.substr(0, dotPosition);
        string fractionalPart = value.substr(dotPosition + 1);

        int integerValue = stoi(integerPart);
        int fractionalValue = stoi(fractionalPart);

        int numerator;

        if (integerValue >= 0)
            numerator =
            integerValue * denominator + fractionalValue;
        else
            numerator =
            integerValue * denominator - fractionalValue;

        Fraction fraction(numerator, denominator);

        fraction.print();
    }
};

int Fraction::count = 0;


int main()
{
    Fraction first(1, 2);
    Fraction second(3, 4);

    cout << "First fraction: ";
    first.print();

    cout << "\nSecond fraction: ";
    second.print();

    Fraction sum = first + second;
    Fraction difference = first - second;
    Fraction multiplication = first * second;
    Fraction division = first / second;

    cout << "\n\nAddition: ";
    sum.print();

    cout << "\nSubtraction: ";
    difference.print();

    cout << "\nMultiplication: ";
    multiplication.print();

    cout << "\nDivision: ";
    division.print();

    cout << "\n\nGCD(24, 18): "
        << Fraction::gcd(24, 18);

    cout << "\n\n0.43 as fraction: ";
    Fraction::printAsFraction(0.43);

    char value[] = "0.25";

    cout << "\n0.25 as fraction: ";
    Fraction::printAsFraction(value);

    cout << "\n\nCurrent number of Fraction objects: "
        << Fraction::getCount();

    return 0;
}
