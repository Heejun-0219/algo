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

    vector<long long> pre_sum(N + 1);

    pre_sum[0] = 0;
    pre_sum[1] = A[0];
    for (int i = 2; i <= N; i++){
        pre_sum[i] = pre_sum[i - 1] + A[i - 1];
    }

    int count = N - M + 1;
    vector<long long> val(count);
    val[0] = pre_sum[M];
    for (int i = 1; i < count; i++){
        val[i] = pre_sum[i + M] - pre_sum[i];
    }

    // for (auto it : val) cout << it << " ";
    cout << *max_element(val.begin(), val.end());

    return 0;
}
