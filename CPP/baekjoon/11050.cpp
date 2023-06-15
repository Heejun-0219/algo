#include <iostream>

long long int factorial(long long int N)
{
    long long int val = 1;

    for (int i = 1; i <= N; i++)
    {
        val *= i;
    }

    return val;
}

int main()
{
    int N, K;
    std::cin >> N >> K;

    long long int val = 1;

    val *= (factorial(N) / (factorial(K) * factorial(N-K)));

    std::cout << val;

    return 0;
}

// #include <iostream>
// using namespace std;

// // 팩토리얼 함수
// int factorial(int n) {
//     int result = 1;
//     for (int i = 1; i <= n; i++) {
//         result *= i;
//     }
//     return result;
// }

// int main() {
//     int N, K;
//     cin >> N >> K;

//     // 이항 계수 공식 사용
//     int answer = factorial(N) / (factorial(K) * factorial(N - K));
//     cout << answer;

//     return 0;
// }
