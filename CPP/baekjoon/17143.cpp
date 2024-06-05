#include <iostream>
#include <cstring>
#define max_n 100
using namespace std;

struct shark
{
    int y, x, s, dir, z, alive;
}shark[max_n*max_n];

int r, c, m, ret, map[max_n][max_n], tmp[max_n][max_n];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> m;
    for (int i = 1; i <= m; i++) {
        cin >> shark[i].y >> shark[i].x >> shark[i].s >> shark[i].dir >> shark[i].z;
        shark[i].y--; shark[i].x--; shark[i].dir--;

        if (shark[i].dir <= 1) shark[i].s %= (2 * (r - 1));
        else shark[i].s %= (2 * (c - 1));
        
        map[shark[i].y][shark[i].x] = i;
    }
    for (int t = 0; t < c; t++) {
        for (int y = 0; y < r; y++) {
            if (map[y][t]) {
                shark[map[y][t]].alive = 1;
                ret += shark[map[y][t]].z;
                map[y][t] = 0;
                break;
            }
        }
        memset(tmp, 0, sizeof(tmp));
        for (int i = 1; i <= m; i++) {
            if (shark[i].alive) continue;

            int y = shark[i].y;
            int x = shark[i].x;
            int s = shark[i].s;
            int d = shark[i].dir;
            int ny, nx;

            while (true)
            {
                ny = y + s * dy[d];
                nx = x + s * dx[d];
                if (nx < c && ny < r && ny >= 0 && nx >= 0) break;
                if (d <= 1) {
                    if (ny < 0) {
                        s -= y;
                        y = 0;
                    }
                    else {
                        s -= r - 1 -y;
                        y = r - 1;
                    }
                }
                else {
                    if (nx < 0) {
                        s -= x;
                        x = 0;
                    }
                    else {
                        s -= c - 1 -x;
                        x = c -1;
                    }
                }
                d ^= 1;
            }
            
            if (tmp[ny][nx]) {
                if (shark[tmp[ny][nx]].z < shark[i].z) {
                    shark[tmp[ny][nx]].alive = 1;
                    tmp[ny][nx] = i;
                }
                else shark[i].alive = 1;
            }
            else tmp[ny][nx] = i;

            shark[i].y= ny;
            shark[i].x = nx;
            shark[i].dir = d;
        }
        memcpy(map, tmp, sizeof(map));
    }
    cout << ret << '\n';

    return 0;
}
