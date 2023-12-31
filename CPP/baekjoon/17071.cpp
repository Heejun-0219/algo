#include <bits/stdc++.h>
using namespace std;

int subin, brother;
const int MAX = 500000;
int visited[2][MAX + 4];
int step = 1;
bool ok = false;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> subin >> brother;
    if (subin == brother) {
        cout << "0\n";
        return 0;
    }

    visited[0][subin] = 1;
    queue<int> q;
    q.push(subin);
    while (q.size())
    {
        brother += step;
        if (brother > MAX) break;
        if (visited[step % 2][brother]) {
            ok = true;
            break;
        }
        int now_q_size = q.size();
        for (int i = 0; i < now_q_size; i++) {
            int now = q.front();
            q.pop();
            int next_positions[] = {now-1, now+1, now*2};
            for (int next : next_positions) {
                if (0 > next || next > MAX || visited[step % 2][next]) continue;
                visited[step % 2][next] = visited[(step + 1) % 2][now] + 1;
                if (next == brother) {
                    ok = true;
                    break;
                }
                q.push(next);
            }
        }
        if (ok) break;
        // cout << "bro :" << brother << endl;
        step++;
    }

    if (ok) cout << step << "\n";
    else cout << -1 << '\n';

    return 0;
}