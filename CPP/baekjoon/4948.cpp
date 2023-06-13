#include <iostream>
#include <vector>

int sieveOfEratosthenes(int start, int end)
{
    std::vector<bool> prime(end + 1, true); // 초기에 모든 수를 소수로 가정
    int count = 0;

    prime[0] = prime[1] = false;
    for (long long int p = 2; p <= end / p; ++p)
    {
        if (prime[p])
        {
            for (long long int i = p * p; i <= end; i += p)
            {
                prime[i] = false;
            }
        }
    }

        for (long long int p = start; p <= end; ++p)
    {
        if (prime[p])
        {
            count++;
        }
    }
    return count;
}

int main(){
    int val;
    int count;

    std::cin >> val;
    while (val != 0)
    {
        count = sieveOfEratosthenes(val + 1, 2 * val);
        std::cout << count << '\n';

        std::cin >> val;
    }
    
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// // 에라토스테네스의 체를 이용하여 소수를 판별하는 함수
// vector<bool> primeSieve(int n) {
//     vector<bool> isPrime(n + 1, true);
//     isPrime[0] = isPrime[1] = false;

//     int sqrtN = sqrt(n);
//     for (int i = 2; i <= sqrtN; i++) {
//         if (isPrime[i]) {
//             for (int j = i * i; j <= n; j += i) {
//                 isPrime[j] = false;
//             }
//         }
//     }

//     return isPrime;
// }

// int main() {
//     while (true) {
//         int n;
//         cin >> n;

//         if (n == 0)
//             break;

//         vector<bool> isPrime = primeSieve(2 * n);
//         int count = 0;

//         for (int i = n + 1; i <= 2 * n; i++) {
//             if (isPrime[i])
//                 count++;
//         }

//         cout << count << endl;
//     }

//     return 0;
// }
