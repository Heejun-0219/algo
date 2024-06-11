#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, t;
vector<int> center;
int a[51][51], _map[51][51];
int ret;
void rotate_circle(int here, int dir, int t) {
    vector<int> v;
    for (int i = 0; i < m; i++) v.push_back(a[here][i]);
    if (dir == 1) rotate(v.begin(), v.begin() + t, v.end());
    else rotate(v.begin(), v.begin() + m - t, v.end());
    for (int i = 0; i < m; i++) a[here][i] = v[i];
}
void near_circle() {
    for (int i = 1; i <= n; i++) {
        for (int j = center[i], _cnt = 0; _cnt < m; _cnt++, j = (j + 1) % m) {
            if (a[i][j] == 0) continue;

            if (a[i][j] == a[i][(j + 1) % m] || a[i][j] == a[i][(j - 1 + m) % m]) _map[i][j] = 0;
            else _map[i][j] = a[i][j];

            if (i == 1 && (a[i][j] == a[i + 1][j])) _map[i][j] = 0;
            else if (i == n && a[i][j] == a[i - 1][j]) _map[i][j] = 0;
            else if (a[i][j] == a[i + 1][j] || a[i - 1][j]) _map[i][j] = 0;
            else _map[i][j] = a[i][j];
        }
    }
}
void sum_ret() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            ret += a[i][j];
        }
    }
}
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
bool flag = 1;
void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = (x + dx[i] + m) % m;
        if (ny < 0 || ny >= n) continue;
        if (_map[ny][nx]) continue;
        if (a[y][x] == a[ny][nx]) {
            _map[y][x] = _map[ny][nx] = 1;
            flag = 0;
            dfs(ny, nx);
        }
    }
}
bool findAdj() {
    flag = 1;
    memset(_map, 0, sizeof(_map));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 || _map[i][j]) continue;
            dfs(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (_map[i][j]) a[i][j] = 0;
        }
    }
    return flag;
}
void setAver() {
    int _sum = 0, _cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            _sum += a[i][j];
            _cnt++;
        }
    }
    double av = (double)_sum / (double)_cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            else if ((double)a[i][j] > av) a[i][j]--;
            else if ((double)a[i][j] < av) a[i][j]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t;
    center.resize(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int z = 0; z < t; z++) {
        int x, d, k;
        cin >> x >> d >> k;

        ret = 0;
        for (int q = x - 1; q < n; q += x) {
            rotate_circle(q, d, k);
        }
        if (findAdj()) setAver();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ret += a[i][j];
    }
    cout << ret << '\n';
    return 0;
}
