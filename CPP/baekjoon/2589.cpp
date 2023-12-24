#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[51][51], visited[51][51];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
int case_max;
int ret;

void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    while (q.size())
    {
        pair<int, int> front = q.front();
        y = front.first;
        x = front.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push(make_pair(ny, nx));
            ret = max(ret, visited[ny][nx]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'L') {
                a[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    cout << ret - 1 << '\n';

    return 0;
}