#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, mp, mf, ms, mv;
int ret = INF;
struct A {
    int mp, mf, ms, mv, cost;
}a[16];
map<int, vector<vector<int> > > v;
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }
    for (int i = 1; i < (1 << n); i++) {
        int b, c, d, e, sum;
        b = c = d = e = sum = 0;
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tmp.push_back(j + 1);
                b += a[j].mp;
                c += a[j].mf;
                d += a[j].ms;
                e += a[j].mv;
                sum += a[j].cost;
            }
        }
        if (mp <= b && mf <= c && ms <= d && mv <= e) {
            if (ret >= sum) {
                ret = sum;
                v[ret].push_back(tmp);
            }
        }
    }
    if (ret == INF) cout << -1 << '\n';
    else {
        sort(v[ret].begin(), v[ret].end());
        cout << ret << '\n';
        for (int i : v[ret][0]) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}