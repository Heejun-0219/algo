#include <bits/stdc++.h>
using namespace std;

int subin, brother;
const int MAX = 100000;
int visited[MAX + 4];
long long cnt[MAX + 4];

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> subin >> brother;
    if (subin == brother) {
        cout << "0\n1\n";
        return 0;
    }

    visited[subin] = 1;
    cnt[subin] = 1;
    queue<int> q;
    q.push(subin);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int next : {now-1, now+1, now*2}) {
            if (0 <= next && next <= MAX) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                }
                else if (visited[next] == visited[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }
        }
    }    

    cout << visited[brother] - 1 << '\n' << cnt[brother] << '\n';

    return 0;
}