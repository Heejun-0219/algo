#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> table(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];

            if (i > 0) table[i][j] += table[i - 1][j];
            if (j > 0) table[i][j] += table[i][j - 1];

            if (i > 0 && j > 0) table[i][j] -= table[i - 1][j - 1];
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = table[x2 - 1][y2 - 1];
        if (x1 > 1) result -= table[x1 - 2][y2 - 1];
        if (y1 > 1) result -= table[x2 - 1][y1 - 2];
        if (x1 > 1 && y1 > 1) result += table[x1 - 2][y1 - 2];

        cout << result << '\n';
    }

    return 0;
}
