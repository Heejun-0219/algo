#include <bits/stdc++.h>
using namespace std;

char arr[65][65];
int n;

string dfs(int y, int x, int size) {
    if (size == 1) return string(1, arr[y][x]);

    char b = arr[y][x];
    string ret = "";
    bool flag = 0;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (b != arr[i][j]) {
                ret += '(';
                ret += dfs(y, x, size / 2);
                ret += dfs(y, x + size / 2, size / 2);
                ret += dfs(y + size / 2, x, size / 2);
                ret += dfs(y + size / 2, x + size / 2, size / 2);
                ret += ')';
                return ret;
            }
        }
    }
    return string(1, arr[y][x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j];
        }
    }

    cout << dfs(0, 0, n) << "\n";

    return 0;
}
