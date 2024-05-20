#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[104], visited[104], n, k, cnt;
vector<int> v;
const int INF = 987654321;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        if (visited[a[i]]) continue;
        if (v.size() == n) {
            int last = 0, pos;
            for (int j : v) {
                int now = INF;
                for (int z = i + 1; z < k; z++) {
                    if (j == a[z]) {
                        now = z;
                        break;
                    }
                }
                if (now > last) {
                    last = now;
                    pos = j;
                }
            }
            visited[pos] = 0;
            cnt++;
            v.erase(find(v.begin(), v.end(), pos));
        }
        v.push_back(a[i]);
        visited[a[i]] = 1;
    }
    cout << cnt << endl;
    return 0;
}
