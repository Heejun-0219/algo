#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N + 1, 0);
    vector<int> dp(N + 1, 1);
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    for (int i = 2; i <= N; i++){
        for (int j = 1; j < i; j++){
            if (dp[i] < dp[j] + 1 && A[i] > A[j]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int N;
//     cin >> N;

//     vector<int> A(N);
//     vector<int> dp(N, 1); // 각 원소별로 최소 길이는 1

//     for (int i = 0; i < N; ++i) {
//         cin >> A[i];
//     }

//     for (int i = 1; i < N; ++i) {
//         for (int j = 0; j < i; ++j) {
//             if (A[i] > A[j] && dp[i] < dp[j] + 1) {
//                 dp[i] = dp[j] + 1;
//             }
//         }
//     }

//     int max_length = 0;
//     for (int i = 0; i < N; ++i) {
//         if (dp[i] > max_length) {
//             max_length = dp[i];
//         }
//     }

//     cout << max_length << endl;

//     return 0;
// }
