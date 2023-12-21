#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[10004];
int visited[10004];
int dp[10004];

int dfs(int here) {
    visited[here] = 1;
    int ret = 1;
    for (int there : adj[here]) {
        if (visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    int val_max = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        val_max = max(val_max, dp[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (val_max == dp[i]) cout << i << " ";
    }

    return 0;
}