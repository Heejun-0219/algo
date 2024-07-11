#include <iostream>
#include <vector>

using namespace std;
int n, m, ret = 987654321;
int a[10][10];
vector<pair<int,int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> extendCC(int here, int dir) {
    vector<pair<int, int>> _changed;
    int y = v[here].first;
    int x = v[here].second;
    if (a[y][x] == 1) {
        while (1)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                if (a[ny][nx] == 0) {
                    a[ny][nx] = 9; _changed.push_back(make_pair(ny, nx));
                }
                y = ny; x = nx;

            }
            else break;
        }
    }
    else if (a[y][x] == 2) {
        for (int i = 0; i <= 2; i +=2) {
            int _y = y;
            int _x = x;
            while (1)
            {
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 9; _changed.push_back(make_pair(ny, nx));
                    }
                    _y = ny; _x = nx;
                }
                else break;
            }
            
        }
    }
    else if (a[y][x] == 3) {
        for (int i = 0; i < 2; i++) {
            int _y = y;
            int _x = x;
            while (1)
            {
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 9; _changed.push_back(make_pair(ny, nx));
                    }
                    _y = ny; _x = nx;
                }
                else break;
            }
            
        }
    }
    else if (a[y][x] == 4) {
        for (int i = 0; i < 3; i++) {
            int _y = y;
            int _x = x;
            while (1)
            {
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 9; _changed.push_back(make_pair(ny, nx));
                    }
                    _y = ny; _x = nx;
                }
                else break;
            }
        }
    }
    else if (a[y][x] == 5) {
        for (int i = 0; i < 4; i++) {
            int _y = y;
            int _x = x;
            while (1)
            {
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 9; _changed.push_back(make_pair(ny, nx));
                    }
                    _y = ny; _x = nx;
                }
                else break;
            }
        }
    }

    return _changed;
}
void dfs(int here) {
    if (here == v.size()) {
        int _cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) _cnt++;
            }
        }
        ret = min(ret, _cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        vector<pair<int, int>> _changed = extendCC(here, i);
        dfs(here + 1);
        for (auto j : _changed) a[j.first][j.second] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0 && a[i][j] != 6) v.push_back(make_pair(i, j));
        }
    }
    dfs(0);
    cout << ret << '\n';

    return 0;
}
