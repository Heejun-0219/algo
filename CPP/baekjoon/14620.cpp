#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, flower_min = INF;
int a[14][14], visited[14][14];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int setFlower(int y, int x) {
    visited[y][x] = 1;
    int sum = a[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        sum += a[ny][nx];
    }
    return sum;
}

bool check(int y, int x) {
    if (visited[y][x]) return 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) return 0;
    }
    return 1;
}

void eraseFlower(int y, int x) {
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

void go(int cnt, int val) {
    if (cnt == 3) {
        flower_min = min(flower_min, val);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                go(cnt + 1, val + setFlower(i, j));
                eraseFlower(i, j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 0);

    cout << flower_min << '\n';
    return 0;
}
