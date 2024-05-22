#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int n;
int ret;

struct Board {
    int map[21][21];

    void find_max() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret = max(ret, map[i][j]);
            }
        }
    }

    void move() {
        int tmp[21][21] = { 0, };
        for (int i = 0; i < n; i++) {
            bool flag = false;
            int c = -1;
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 0) continue;
                else if (flag && map[i][j] == tmp[i][c]) {
                    tmp[i][c] *= 2;
                    flag = false;
                }
                else {
                    flag = true;
                    tmp[i][++c] = map[i][j];
                }
            }
        }
        memcpy(map, tmp, sizeof(map));
    }

    void rotate() {
        int tmp[21][21];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp[n - j - 1][i] = map[i][j];
            }
        }
        memcpy(map, tmp, sizeof(map));
    }
};
void dfs(Board b, int index) {
    if (index == 5) {
        b.find_max();
        return;
    }

    for (int i = 0; i < 4; i++) {
        Board c = b;
        c.move();
        dfs(c, index + 1);
        b.rotate();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    Board b;
    for (int i = 0;  i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b.map[i][j];
        }
    }

    dfs(b, 0);
    cout << ret;

    return 0;
}
