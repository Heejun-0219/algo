#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int a[54][54], visited[54][54];
vector<pair<int, int> > adj[54];
int group;

void dfs(int y, int x) {
    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx]) continue;
        int tmp = abs(a[y][x] - a[ny][nx]);
        if (tmp < l || tmp > r) continue;

        adj[group].push_back(make_pair(ny, nx));

        visited[ny][nx] = 1;
        dfs(ny, nx);
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    while (++cnt)
    {
        group = 0;
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    adj[group].push_back(make_pair(i, j));
                    visited[i][j] = 1;
                    dfs(i, j);
                    group++;
                }
            }
        }

        // break
        if (group == n * n)
            break;

        // cal
        for (int i = 0; i < group; i++) {
            long long sum = 0;
            int g_size = adj[i].size();

            for (pair<int, int> p : adj[i]) {
                sum += a[p.first][p.second];
            }

            sum /= g_size;
            for (pair<int, int> p : adj[i]) {
                a[p.first][p.second] = sum;
            }
        }
        
    }
    
    cout << cnt - 1 << '\n';

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cstring>
// using namespace std;

// int N, L, R;
// int A[50][50];
// bool visited[50][50];

// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};

// bool isOpen(int x, int y, int nx, int ny) {
//     int diff = abs(A[x][y] - A[nx][ny]);
//     return diff >= L && diff <= R;
// }

// bool processUnion(int x, int y) {
//     vector<pair<int, int>> unionCountries;
//     queue<pair<int, int>> q;
//     q.push({x, y});
//     visited[x][y] = true;
//     unionCountries.push_back({x, y});

//     int sum = A[x][y];
//     while (!q.empty()) {
//         int cx = q.front().first;
//         int cy = q.front().second;
//         q.pop();

//         for (int i = 0; i < 4; ++i) {
//             int nx = cx + dx[i];
//             int ny = cy + dy[i];
//             if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && isOpen(cx, cy, nx, ny)) {
//                 visited[nx][ny] = true;
//                 q.push({nx, ny});
//                 unionCountries.push_back({nx, ny});
//                 sum += A[nx][ny];
//             }
//         }
//     }

//     if (unionCountries.size() > 1) {
//         int newPop = sum / unionCountries.size();
//         for (auto &p : unionCountries) {
//             A[p.first][p.second] = newPop;
//         }
//         return true;
//     }
//     return false;
// }

// int main() {
//     cin >> N >> L >> R;
//     for (int i = 0; i < N; ++i)
//         for (int j = 0; j < N; ++j)
//             cin >> A[i][j];

//     int days = 0;
//     while (true) {
//         memset(visited, 0, sizeof(visited));
//         bool moved = false;
//         for (int i = 0; i < N; ++i) {
//             for (int j = 0; j < N; ++j) {
//                 if (!visited[i][j] && processUnion(i, j))
//                     moved = true;
//             }
//         }
//         if (!moved) break;
//         days++;
//     }

//     cout << days;
//     return 0;
// }
