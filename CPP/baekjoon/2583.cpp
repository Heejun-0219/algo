#include <bits/stdc++.h>

using namespace std;
int m, n, k;
int arr[101][101], visited[101][101];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

void make_square(int x1, int y1, int x2, int y2) {
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            arr[j][i] = 1;
        }
    }
}

int dfs(int y, int x) {
    visited[y][x] = 1;
    int d = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= m || nx < 0 || nx >= n || arr[ny][nx] == 1) continue;
        if (visited[ny][nx]) continue;
        d += dfs(ny, nx);
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    vector<int> ret;

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        make_square(x1, y1, x2, y2);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0 && arr[i][j] == 0) {
                ret.push_back(dfs(i, j));
            }
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    return 0;
}