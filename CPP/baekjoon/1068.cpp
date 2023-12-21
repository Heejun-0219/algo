#include <bits/stdc++.h>

using namespace std;

int n, r, root;
vector<int> adj[55];

int dfs(int here) {
    int cnt = 0;
    int child = 0;
    for (int there : adj[here]) {
        if (there == r) continue;
        cnt += dfs(there);
        child++;
    }
    if (child == 0) return 1;
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == -1) root = i;
        else adj[tmp].push_back(i);
    }

    cin >> r;
    if (root == r) {
        cout << 0 << "\n";
    }
    else {
        cout << dfs(root) << "\n";
    }

    return 0;
}