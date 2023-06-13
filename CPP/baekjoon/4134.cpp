#include <iostream>
#include <vector>

inline bool isPrime(long long int val)
{
    if (val <= 1)
        return false;

    for (long long int i = 2; i <= val / i; i++)
    {
        if (val % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int N;
    std::cin >> N;

    long long int val;
    for (int i = 0; i < N; i++)
    {
        std::cin >> val;

        while (!isPrime(val++));
        std::cout << val - 1 << '\n';
    }

    return 0;
}