#include <bits/stdc++.h>
using namespace std;

class BigInteger
{
private:
    string number;

public:
    BigInteger() : number("0") {}
    BigInteger(const string &str) : number(str) {}

    // Addition
    BigInteger operator+(const BigInteger &other) const
    {
        string result;
        int carry = 0;

        int i = number.length() - 1;
        int j = other.number.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            int num1 = (i >= 0) ? number[i] - '0' : 0;
            int num2 = (j >= 0) ? other.number[j] - '0' : 0;

            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum %= 10;

            result += to_string(sum);

            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return BigInteger(result);
    }

    // Subtraction
    BigInteger operator-(const BigInteger &other) const
    {
        // You can implement subtraction here.
        // This is a simplified example and doesn't handle borrow properly.
        // You might want to implement a more robust subtraction method.
        return *this;
    }

    // Multiplication
    BigInteger operator*(const BigInteger &other) const
    {
        // You can implement multiplication here.
        // This is a simplified example and doesn't handle large numbers efficiently.
        return *this;
    }

    // Division
    BigInteger operator/(const BigInteger &other) const
    {
        // You can implement division here.
        // This is a simplified example and doesn't handle division by zero or large numbers efficiently.
        return *this;
    }

    friend ostream &operator<<(ostream &os, const BigInteger &bigInt)
    {
        os << bigInt.number;
        return os;
    }
};

int main()
{

    return 0;
}