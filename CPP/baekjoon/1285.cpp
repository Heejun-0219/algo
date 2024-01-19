#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, ret = INF;
vector<int> v;
void go(int here) {
    if (here == n + 1) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
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
    v.resize(n, (1 << n));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'T') {
                v[i] |= (1 << j);
            }
        }
    }

    go(1);
    cout << ret << '\n';

    return 0;
}