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

long long int get_Binom(long long int N, long long int K)
{
    if (N == K)
        return 1;
    // return (factorial(N) / (factorial(K) * factorial(N - K)));

    if (K > N / 2)
        K = N - K;

    long long int val = 1;
    for (int i = 1; i <= K; i++){
        val *= N--;
    }

    return val / factorial(K);
}

int main()
{
    int testCase;
    std::cin >> testCase;

    int N, M;
    while (testCase--)
    {
        std::cin >> N >> M;

        std::cout << get_Binom(M, N) << '\n';
    }

    return 0;
}

// #include <iostream>
// using namespace std;

// #define MAX 41
// long long comb[MAX][MAX];

// // 이항 계수를 미리 계산하는 함수
// void precalc() {
//     for(int i = 0; i <= MAX - 1; i++) {
//         comb[i][0] = comb[i][i] = 1;
//         for(int j = 1; j < i; j++) {
//             comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
//     precalc();
//     int T, N, M;
//     cin >> T;
//     while(T--) {
//         cin >> N >> M;
//         cout << comb[M][N] << "\n";
//     }
//     return 0;
// }
