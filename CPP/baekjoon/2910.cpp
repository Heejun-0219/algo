#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > v;
map<int, int> mp, fir;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return fir[a.second] < fir[b.second];
    }
    return a.first > b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    long long n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        long long val;
        cin >> val;
        mp[val]++;
        if (fir[val] == 0) fir[val] = i + 1;
    }
    for (auto it : mp) {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto i : v) {
        for (int j = 0; j < i.first; j++) {
            cout << i.second << " ";
        }
    }
    
    return 0;
}