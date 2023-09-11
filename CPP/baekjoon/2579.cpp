#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> score(n+1, 0);
    vector<int> dp(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    dp[1] = score[1];
    if (n > 1) {
        dp[2] = score[1] + score[2];
    }

    for(int i = 3; i <= n; i++) {
        dp[i] = max(score[i] + dp[i-2], score[i] + score[i-1] + dp[i-3]);
    }

    cout << dp[n] << endl;

    return 0;
}
