#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, m, k, r, c, s, ret = INF;
int a[51][51], c_map[51][51];
pair<int, int> left_top, right_bottom;
int dy[] = {0, 1, 0 , -1};
int dx[] = {1, 0, -1, 0};
struct A
{
    int r, c, s;
};

vector<A> info;
vector<int> v;
void copy_map(int y, int x, int step) {
    int ny = y + dy[step];
    int nx = x + dx[step];

    if (ny < left_top.first || nx < left_top.second || nx > right_bottom.second || ny > right_bottom.first) {
        step++;
        ny = y; nx = x;
    }
    else {
        c_map[ny][nx] = a[y][x];
    }

    if (step >= 4) return;
    copy_map(ny, nx, step);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        cin >> r >> c >> s;
        info.push_back({r, c, s});
        v.push_back(i);
    }

    int tmp[51][51];
    memcpy(tmp, a, sizeof(a));
    do
    {
        memcpy(a, tmp, sizeof(tmp));
        memcpy(c_map, a, sizeof(c_map));

        for (int i : v) {
            left_top = make_pair(info[i].r - info[i].s - 1, info[i].c - info[i].s - 1);
            right_bottom = make_pair(info[i].r + info[i].s - 1, info[i].c + info[i].s - 1);

            while (left_top.first != right_bottom.first)
            {
                copy_map(left_top.first, left_top.second, 0);
                left_top.first++; left_top.second++;
                right_bottom.first--; right_bottom.second--;
            }
            memcpy(a, c_map, sizeof(a));
        }

        int _sum;
        for (int i = 0; i < n; i++) {
            _sum = 0;
            for (int j = 0; j < m; j++) {
                _sum += a[i][j];
            }
            ret = min(ret, _sum);
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << ret << '\n';

    return 0;
}
