#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
vector<int> a[1004];
int visited[1004];

void dfs(int i) {
    visited[i] = 1;
    for (int here : a[i]) {
        if (!visited[here]) dfs(here);
    }
}
bool checkTree() {
    cin >> n >> m;

    for (int i = 0; i < 1004; i++) {
        a[i].clear();
    }
    fill(visited, visited + 1004, 0);

    for (int i = 0; i < m; i++) {
        int front, back;

        cin >> front >> back;

        a[front].push_back(back);
        a[back].push_back(front);    
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    return (cnt == 1 && m + 1 == n ? true : false);
}

int main() {
    cin >> t;

    while (t--)
    {
        bool flag;

        flag = checkTree();

        if (flag) {
            cout << "tree" << endl;
        }
        else 
            cout << "graph" << endl;
    }

    return 0;
}
