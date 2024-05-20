#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[51][51], copy_map[51][51], r, c, t;
long long ret;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int top[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int bottom[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
pair<int, int> pos[2];

void dust(int y, int x) {
    int side = a[y][x] / 5;

    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (a[ny][nx] < 0) continue;
        cnt++;
        copy_map[ny][nx] += side;
    }
    a[y][x] -= side * cnt;
}

void fir_d(int y, int x, int index) {
    int ny, nx;

    if (index == 0) {
        nx = x;
        ny = y - 1;
        if (ny < 0) {
            index++;
            ny = 0;
        }
    }
    else if (index == 1) {
        ny = y;
        nx = x + 1;
        if (nx >= c) {
            index++;
            nx = x;
        }
    }
    else if (index == 2) {
        nx = x;
        ny = y + 1;
        if (ny == pos[1].first) {
            index++;
            ny = y;
        }
    }
    else {
        ny = y;
        nx = x - 1;
        if (nx == pos[0].second) {
            a[y][x] = 0;
            return;
        }
    }

    a[y][x] = a[ny][nx];
    fir_d(ny, nx, index);
}

void sec_d(int y, int x, int index) {
    int ny, nx;

    if (index == 0) {
        nx = x;
        ny = y + 1;
        if (ny >= r) {
            index++;
            ny = y;
        }
    }
    else if (index == 1) {
        ny = y;
        nx = x + 1;
        if (nx >= c) {
            index++;
            nx = x;
        }
    }
    else if (index == 2) {
        nx = x;
        ny = y - 1;
        if (ny == pos[0].first) {
            index++;
            ny = y;
        }
    }
    else {
        ny = y;
        nx = x - 1;
        if (nx == pos[1].second) {
            a[y][x] = 0;
            return;
        }
    }

    a[y][x] = a[ny][nx];
    sec_d(ny, nx, index);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int d = 0;

    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                pos[d] = make_pair(i, j);
                a[i][j] -= d++;
            }
        }
    }

    while (t--)
    {
        d = 0;
        memset(copy_map, 0, sizeof(copy_map));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dust(i, j);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                a[i][j] += copy_map[i][j];
            }
        }
        fir_d(pos[d].first - 1, pos[d].second, 0);
        d++;
        sec_d(pos[d].first + 1, pos[d].second, 0);

        // cout << "-------------------------------------------------\n";
        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ret += a[i][j];
        }
    }
    cout << ret + 3 << '\n';

    return 0;
}
