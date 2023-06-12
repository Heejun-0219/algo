#include <iostream>

long long int get_gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    else
        return get_gcd(b, a % b);
}

int main()
{
    long long int A1, A2, B1, B2;
    std::cin >> A1 >> B1 >> A2 >> B2;

    long long int Max_divisor, Min_mul;
    Max_divisor = get_gcd(B1, B2);
    Min_mul = B1 * B2 / Max_divisor;

    long long int val = (A1 * Min_mul / B1) + (A2 * Min_mul / B2);
    Max_divisor = get_gcd(val, Min_mul);
    std::cout << val / Max_divisor << " " << Min_mul / Max_divisor;

    return 0;
}

// #include <iostream>

// // Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
// int gcd(int a, int b) {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// // Function to simplify a fraction
// void simplifyFraction(int& numerator, int& denominator) {
//     int commonDivisor = gcd(numerator, denominator);
//     numerator /= commonDivisor;
//     denominator /= commonDivisor;
// }

// // Function to add two fractions and return the result as a simplified fraction
// void addFractions(int num1, int denom1, int num2, int denom2, int& resultNum, int& resultDenom) {
//     // Find a common denominator
//     int commonDenom = denom1 * denom2;

//     // Calculate the numerators for the new fractions
//     int newNum1 = num1 * denom2;
//     int newNum2 = num2 * denom1;

//     // Calculate the sum of the numerators
//     resultNum = newNum1 + newNum2;
//     resultDenom = commonDenom;

//     // Simplify the result fraction
//     simplifyFraction(resultNum, resultDenom);
// }

// int main() {
//     int num1, denom1, num2, denom2;
//     std::cin >> num1 >> denom1;
//     std::cin >> num2 >> denom2;

//     int resultNum, resultDenom;
//     addFractions(num1, denom1, num2, denom2, resultNum, resultDenom);

//     std::cout << resultNum << " " << resultDenom << std::endl;

//     return 0;
// }
