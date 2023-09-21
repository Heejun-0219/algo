#include <bits/stdc++.h>

using namespace std;

bool index_third_ascendingOrder(const vector<double>& a, const vector<double>& b) {
    return a[2] > b[2];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    
    vector<int> weight(N + 1, 0);
    vector<int> value(N + 1, 0);
    for (size_t i = 1; i <= N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    vector<vector<int> > dp(N + 1, vector<int>(K + 1, 0));
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= K; j++)
        {
            if (weight[i] <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    cout << dp[N][K];

    return 0;
}
