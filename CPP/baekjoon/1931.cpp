#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        int front, back;
        cin >> front >> back;

        v.push_back(make_pair(back, front));
    }
    sort(v.begin(), v.end());

    int ret = 1;
    int time = v[0].first;
    for (int i = 1; i < n; i++) {
        if (v[i].second < time) continue;
        time = v[i].first;
        ret++;
    }
    cout << ret << endl;

    return 0;
}
