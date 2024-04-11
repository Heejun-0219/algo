#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 987654321;
int result = INF;
int n, tmp, m;
vector<int> adj[11];
int people[11], component[11], visited[11];

pair<int, int> dfs(int index, int area) {
    visited[index] = 1;
    pair<int, int> value = {1, people[index]};
    for (int there : adj[index]) {
        if (component[there] != area) continue;
        if (visited[there]) continue;
        pair<int, int> _tmp = dfs(there, area);
        value.first += _tmp.first;
        value.second += _tmp.second;
    }
    return value;
}
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        people[i] = tmp;
    }

    for (int i = 1; i <= n; i++) {
        int size;
        cin >> size;

        for (int j = 0; j < size; j++) {
            cin >> tmp;
            adj[i].push_back(tmp);
            adj[tmp].push_back(i);
        }
    }

    for (int i = 1; i < (1 << n) - 1; i++) {
        memset(component, 0, sizeof(component));
        memset(visited, 0, sizeof(visited));
        int index1 = -1, index2 = -1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                component[j + 1] = 1;
                index1 = j + 1;
            }
            else {
                index2 = j + 1;
            }
        }
        pair<int, int> area1 = dfs(index1, 1);
        pair<int, int> area2 = dfs(index2, 0);
        if (area1.first + area2.first == n) result = min(result, abs(area1.second - area2.second));
    }

    if (result == INF) {
        cout << -1 << endl;
    }
    else {
        cout << result << endl;
    }
    return 0;
}
