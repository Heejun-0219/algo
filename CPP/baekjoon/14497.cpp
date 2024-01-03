#include <bits/stdc++.h>
using namespace std;

int a[304][304], visited[304][304];
pair<int, int> ju, cho;
int n, m;
int ret;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

void make_zero(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;

        visited[ny][nx] = 1;
        if (a[ny][nx] == 0)
            make_zero(ny, nx);
        else 
            a[ny][nx] = 0;
    }
}

bool chocol_live() {
    if (a[cho.first - 1][cho.second - 1] != 3)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> ju.first >> ju.second >> cho.first >> cho.second;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '1') a[i][j] = 1;
            else if (c == '0') a[i][j] = 0;
            else if (c == '#') a[i][j] = 3;
            else if (c == '*') a[i][j] = 4;
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(ju.first - 1, ju.second - 1));
    while (q.size())
    {
        memset(visited, 0, sizeof(visited));
        visited[ju.first - 1][ju.second - 1] = 1;
        if (chocol_live()) break;

        ret++;

        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // cout << "y: " << ny << " x: " << nx << " a: " << a[ny][nx] << endl;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = 1;
            if (a[ny][nx] == 0) {
                make_zero(ny, nx);
                q.push(make_pair(ny, nx));
            }
            else if (a[ny][nx] == 1) {
                a[ny][nx] = 0;
            }
            else if (a[ny][nx] == 3) {
                a[ny][nx] = 5;
            }
        }
        q.push(make_pair(ju.first - 1, ju.second - 1));
    }
    
    cout << ret << '\n';

    return 0;
}