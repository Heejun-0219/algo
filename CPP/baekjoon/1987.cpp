#include <bits/stdc++.h>

using namespace std;
int r, c;
char a[21][21], visited[21][21];
vector<char> v;
string s;
int max_cnt;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

void print_vector() {
    for (char ch : v) {
        cout << ch << " ";
    }
    cout << endl;
}

void dfs(int y, int x) {
    v.push_back(a[y][x]);
    visited[y][x] = 1;
    if (max_cnt < v.size()) max_cnt = v.size();

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
        if (find(v.begin(), v.end(), a[ny][nx]) != v.end()) continue;

        dfs(ny, nx);
    }

    visited[y][x] = 0;
    v.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            a[i][j] = s[j];
        }
    }

    dfs(0, 0);

    cout << max_cnt << '\n';

    return 0;
}