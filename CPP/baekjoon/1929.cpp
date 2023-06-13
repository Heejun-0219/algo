#include <iostream>
#include <vector>

void sieveOfEratosthenes(int start, int end)
{
    std::vector<bool> prime(end + 1, true); // 초기에 모든 수를 소수로 가정

    prime[0] = prime[1] = false;
    for (long long int p = 2; p <= end / p; ++p)
    {
        if (prime[p])
        {
            // 현재 숫자가 소수인 경우
            // 그의 배수들은 소수가 아님
            for (long long int i = p * p; i <= end; i += p)
            {
                prime[i] = false;
            }
        }
    }

    // 소수 출력
    for (long long int p = start; p <= end; ++p)
    {
        if (prime[p])
        {
            std::cout << p << '\n';
        }
    }
}

int main()
{
    long long int start, end;
    std::cin >> start >> end;

    sieveOfEratosthenes(start, end);

    return 0;
}
