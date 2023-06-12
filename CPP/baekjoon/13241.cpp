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
    long long int A, B;
    long long int Min_mul, Max_divisor;
    std::cin >> A >> B;

    Max_divisor = get_gcd(A, B);
    Min_mul = A * B / Max_divisor;

    std::cout << Min_mul;

    return 0;
}