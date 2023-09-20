#include <bits/stdc++.h>

using namespace std;

int LCS(string A, string B) {
    int len_A = A.length();
    int len_B = B.length();

    vector<vector<int> > dp(len_A + 1, (vector<int>(len_B + 1, 0)));

    for (size_t i = 1; i <= len_A; i++)
    {
        for (size_t j = 1; j <= len_B; j++)
        {
            if (A[i - 1] == B[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[len_A][len_B];
}

int main(){   
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;

    int result = LCS(A, B);

    cout << result;

    return 0;
}