#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int d, p;
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        q.push(v[i].second);
        if (q.size() > v[i].first) q.pop();
    }

    int ret = 0;
    while (q.size())
    {
        ret += q.top(); q.pop();
    }
    
    cout << ret << endl;


    return 0;
}
