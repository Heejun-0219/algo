#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    deque<int> balloons(N);
    for (int i = 0; i < N; i++) {
        cin >> balloons[i];
    }

    vector<int> ans(N, 1); 
    int idx = 0;
    int move = balloons[idx];
    balloons.erase(balloons.begin());
    for (int i = 1; i < N; i++) {
        ans[i] = 
        move = balloons[idx + move];
    }

    return 0;
}