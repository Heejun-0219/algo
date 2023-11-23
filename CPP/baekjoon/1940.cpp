#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            if (A[i] + A[j] == M) cnt++;
        }
    }
    
    cout << cnt << '\n';

    return 0;
}