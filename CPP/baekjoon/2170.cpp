#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, l, r, sum;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    l = v[0].first;
    r = v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].first > r) {
            sum += r - l;
            l = v[i].first;
            r = v[i].second;
        }
        else if (v[i].first <= r && r <= v[i].second)
            r = v[i].second;
    }
    sum += r - l;
    cout << sum << '\n';
    return 0;
}
