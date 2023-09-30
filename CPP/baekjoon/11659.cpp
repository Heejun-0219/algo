#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<int> pre_sum(N + 1);

    pre_sum[0] = 0;
    pre_sum[1] = A[0];
    for (int i = 2; i <= N; i++){
        pre_sum[i] = pre_sum[i - 1] + A[i - 1];
    }

    while (M--)
    {
        int left, right;

        cin >> left >> right;
        cout << pre_sum[right] - pre_sum[left - 1] << '\n';
    }

    // cout << "\n\n";
    // for (int p : pre_sum) cout << p << " ";

    return 0;
}
