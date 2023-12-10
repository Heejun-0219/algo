#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, j;
    cin >> m >> n >> j;

    int l = 1;
    int r;

    int cnt = 0;
    while (j--)
    {
        r = l + n - 1;

        int line;
        cin >> line;
        if (l <= line && line <= r) continue;
        else {
            if (line < l) {
                cnt += (l - line);
                l = line;
            }
            else {
                l += (line - r);
                cnt += (line - r);
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}