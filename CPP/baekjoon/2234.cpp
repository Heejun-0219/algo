#include <iostream>

using namespace std;
int a[51][51], visited[51][51], roomSize[51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int ret;
int roomCount;
int n, m;
int _size;
int mergeRoomMax;

void dfs(int y, int x, int index) {
    visited[y][x] = index;
    _size++;

    if (_size > ret) ret = _size;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (visited[ny][nx]) continue;
        if (a[y][x] & (1 << i)) continue;

        dfs(ny, nx, index);
    }
}

int mergeCastle(int y, int x) {
    int _ret = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (visited[ny][nx] == visited[y][x]) continue;
        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (!(a[y][x] & (1 << i))) continue;

        int tmp = roomSize[visited[y][x]] + roomSize[visited[ny][nx]];
        _ret = max(_ret, tmp);
    }

    return _ret;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int index = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0) {
                roomCount++;
                dfs(i, j, index);
                roomSize[index++] = _size;
                _size = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mergeRoomMax = max(mergeCastle(i, j), mergeRoomMax);
        }
    }

    cout << roomCount << endl;
    cout << ret << endl;
    cout << mergeRoomMax << endl;

    return 0;
}
