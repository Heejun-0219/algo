#include <iostream>
#include <vector>

using namespace std;
int visited[21][21], a[21][21];
int r, c;
int ret = 0;
int route;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void dfs(int y, int x, int count) {
    ret = max(count, ret);

    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        //if (visited[ny][nx]) continue;
        if (route & (1 << a[ny][nx])) continue;

        // visited[ny][nx] = 1;
        route |= (1 << a[ny][nx]);
        dfs(ny, nx, count + 1);
        // visited[ny][nx] = 0;
        route &= ~(1 << a[ny][nx]);
    }
}
int main() {
    cin >> r >> c;

    string s;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            a[i][j] = s[j] - 65;
        }
    }

    route |= (1 << a[0][0]);
    // cout << route << " ";
    // route &= ~(1 << a[0][0]);
    // cout << route << " ";
    dfs(0,0,1);

    cout << ret << endl;

    return 0;
}
