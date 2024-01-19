#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, ret = INF;
int v[44];
void go(int here) {
    if (here == n + 1) {
        int sum = 0;
        for (int i = 1; i <= (1 << (n - 1)); i*=2) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (v[j] & i) cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return ;
    }
    go(here + 1);
    v[here] = ~v[here];
    go(here + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int val = 1;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'T') {
                v[i] |= val;
            }
            val *= 2;
        }
    }
    go(1);
    cout << ret << '\n';

    return 0;
}