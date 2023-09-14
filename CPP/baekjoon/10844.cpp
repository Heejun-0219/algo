#include <bits/stdc++.h>

#define MOD 1000000000;

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int> > dp(N + 1, vector<int>(10, 0));

    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j - 1 >= 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            if (j + 1 <= 9) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; ++i) {
        result = (result + dp[N][i]) % MOD;
    }

    cout << result << endl;

    return 0;
}
