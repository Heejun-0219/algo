#include <bits/stdc++.h>
using namespace std;

int subin, brother;
const int MAX = 100000;
int visited[MAX + 4];
vector<int> cnt[MAX + 4];
// long long cnt[MAX + 4];

void print_vector(vector<int> v) {
    for (int i : v) {
        cout << i << " ";
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
    cnt[subin].push_back(subin);
    queue<int> q;
    q.push(subin);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        int next_positions[] = {now-1, now+1, now*2};
        for (int next : next_positions) {
            if (0 <= next && next <= MAX) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] = cnt[now];
                    cnt[next].push_back(next);
                }
                else if (visited[next] == visited[now] + 1) {
                    cnt[next] = cnt[now];
                    cnt[next].push_back(next);
                }
            }
        }
    }    

    cout << visited[brother] - 1 << '\n';
    print_vector(cnt[brother]);

    return 0;
}