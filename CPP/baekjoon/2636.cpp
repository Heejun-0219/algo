#include <bits/stdc++.h>
using namespace std;

int n, m;
int cheese[100][100];
int visited[100][100];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
vector<pair<int, int> > v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    if (cheese[y][x] == 1) {
        v.push_back(make_pair(y, x));
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
            continue;

        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cheese[i][j];
        }
    }

    int time = 0, lastCnt = 0;
    while (true) {
        memset(visited, false, sizeof(visited));

        v.clear();
        dfs(0, 0);
        for (pair<int, int> b : v) {
            cheese[b.first][b.second] = 0;
        }

        lastCnt = v.size();
        bool flag = 0;
        for (int i = 0; i < n; i++ ){
            for (int j = 0; j < m; j++) {
                if (cheese[i][j] != 0) flag = 1;
            }
        }

        time++;
        if (!flag) break;
    }

    cout << time << '\n' << lastCnt << '\n';
    return 0;
}
