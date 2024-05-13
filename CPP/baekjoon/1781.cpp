#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > pq;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++)
    {
        int deadline, cup;

        cin >> deadline >> cup;

        v.push_back(make_pair(deadline, cup));
    }
    sort(v.begin(), v.end());

    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret += v[i].second;
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            ret -= pq.top();
            pq.pop();
        }
    }
    cout << ret << endl;

    return 0;
}
