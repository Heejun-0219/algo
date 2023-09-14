#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N + 1, 0);
    vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    dp[1] = A[1];
    if (N > 1){
        dp[2] = A[1] + A[2];
    }

    for (int i = 3; i <= N; i++){
        dp[i] = max(dp[i - 2] + A[i], max(dp[i - 3] + A[i] + A[i - 1], dp[i - 1]));
    }

    cout << dp[N] << '\n';

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
    
//     vector<int> wine(n + 1); // 포도주 양 저장
//     vector<vector<int>> dp(n + 1, vector<int>(3)); // DP 배열, dp[i][j]: i번째 잔까지 마셨을 때 최대 포도주 양(j: 0-현재 안 마심, 1-한 잔 연속으로 마심, 2-두 잔 연속으로 마심)

//     for (int i = 1; i <= n; ++i) {
//         cin >> wine[i];
//     }

//     // DP 진행
//     for (int i = 1; i <= n; ++i) {
//         dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])); // i번째 잔을 안 마신 경우, 이전 잔까지의 최대 양을 그대로 가져옴
//         dp[i][1] = dp[i - 1][0] + wine[i]; // i번째 잔을 마실 경우, 이전 잔을 마시지 않아야 함
//         dp[i][2] = dp[i - 1][1] + wine[i]; // i번째 잔을 마실 경우, 이전 잔을 마셔야 함
//     }

//     int result = max(dp[n][0], max(dp[n][1], dp[n][2])); // 최종 결과는 마지막 잔을 마시지 않은 경우, 한 잔 연속으로 마신 경우, 두 잔 연속으로 마신 경우 중 최댓값

//     cout << result << endl;

//     return 0;
// }
