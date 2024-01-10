#include <bits/stdc++.h>

using namespace std;

int r, c, k, ret;
char a[10][10];
int visited[10][10];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(int y, int x, int cnt) {
    if (cnt > k) return;
    if (cnt == k && y == r - 1 && x == 0) {
        ret++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
        if (a[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    visited[0][c - 1] = 1;
    dfs(0, c - 1, 1);

    cout << ret << '\n';
    return 0;
}