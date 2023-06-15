#include <iostream>
#include <cmath>

int main(){
    int N;
    std::cin >> N;

    std::cout << pow(2, N);

    return 0;
}

// #include<iostream>
// using namespace std;

// int dp[6];

// int main(){
//     int N;
//     cin >> N;

//     dp[1] = 2;
//     for(int i=2; i<=N; i++){
//         dp[i] = 2 * dp[i-1];
//     }

//     cout << dp[N];

//     return 0;
// }
