#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[54][54], ret = INT_MAX;
vector<vector<int> > clist;
vector<pair<int, int> > c, h;
void combi(int start, vector<int> v) {
    if (v.size() == m) {
        clist.push_back(v);
        return;
    }
    for (int i = start + 1; i < c.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                h.push_back(make_pair(i, j));
            }
            if (a[i][j] == 2) {
                c.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> v;
    combi(-1, v);
    for (vector<int> ch : clist) {
        int cnt = 0;
        for (pair<int, int> home : h) {
            int _min = INT_MAX;
            for (int che : ch) {
                int _dis = abs(home.first - c[che].first) + abs(home.second - c[che].second);
                _min = min(_min, _dis);
            }
            cnt += _min;
        }
        ret = min(ret, cnt);
    }
    
    cout << ret << '\n';

    return 0;
}