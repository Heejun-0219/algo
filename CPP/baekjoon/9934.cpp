#include <bits/stdc++.h>
using namespace std;

int k;
int visited[1024], building[1024];
vector<int> a[11];
string s;

void dfs(int here, int depth, int step) {
    if (visited[here] || step < 0) return;

    visited[here] = 1;
    // cout << depth << " " << here << " " << step << " " << building[here] << endl;
    a[depth].push_back(building[here]);
    dfs(here - step, depth + 1, step / 2);
    dfs(here + step, depth + 1, step / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    for (int i = 0; i < pow(2, k) - 1; i++) {
        cin >> building[i];
    }

    dfs(pow(2, k - 1) - 1, 0, pow(2, k - 2));

    for (int i = 0; i < k; i++) {
        for (int val : a[i]) {
            cout << val << " ";
        }
        cout << '\n';
    }

    return 0;
}