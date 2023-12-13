#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;

    vector<vector<int> > m(h, vector<int>(w, -1));
    // vector<vector<int> > c(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++) {
        int cnt = -1;
        for (int j = 0; j < w; j++) {
            char val;
            cin >> val;
            if (val == 'c') {
                m[i][j] = 0;
                cnt = 1;
            }
            else if (cnt > -1) {
                m[i][j] = cnt++;
            }
        }
    }

    for (auto it : m) {
        for (auto i : it) cout << i << " ";
        cout << endl;
    }

    return 0;
}