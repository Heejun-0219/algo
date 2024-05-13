#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long
ll ret, N, K;
vector<pair<ll, ll>> jewel;
vector<ll> bag;
priority_queue<ll> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;

        jewel.push_back(make_pair(m, v));
    }
    sort(jewel.begin(), jewel.end());

    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;

        bag.push_back(c);
    }
    sort(bag.begin(), bag.end());

    for (int i = 0, index = 0; index < K; index++) {
        while (i < N && bag[index] >= jewel[i].first) 
        {
            pq.push(jewel[i++].second);
        }
        if (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << endl;

    return 0;
}
