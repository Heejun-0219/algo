#include <bits/stdc++.h>
using namespace std;

int subin, brother;
const int MAX = 200000;
int visited[MAX + 4], prev_c[MAX + 4];

void print_vector(vector<int> v) {
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> subin >> brother;
    if (subin == brother) {
        cout << "0\n" << subin << '\n';
        return 0;
    }

    visited[subin] = 1;
    queue<int> q;
    q.push(subin);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        if (now == brother) break;
        int next_positions[] = {now-1, now+1, now*2};
        for (int next : next_positions) {
            if (0 > next || next > MAX || visited[next]) continue;
            visited[next] = visited[now] + 1;
            prev_c[next] = now;
            q.push(next);
        }
    }

    vector<int> v;
    for (int i = brother; i != subin; i = prev_c[i]) {
        v.push_back(i);
    }
    v.push_back(subin);

    cout << visited[brother] - 1 << '\n';
    print_vector(v);

    return 0;
}