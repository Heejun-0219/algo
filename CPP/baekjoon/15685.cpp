#include <iostream>
#include <vector>

using namespace std;

int x, y, d, g;
int n, _map[101][101], _count;
int dy[] = {0,-1,0,1};
int dx[] = {1,0,-1,0};
vector<int> dragon[4][11];
void makeDragon() {
    for (int i = 0; i < 4; i++) {
        dragon[i][0].push_back(i);
        dragon[i][1].push_back((i + 1) % 4);
        for (int j = 2; j <= 10; j++) {
            int n = dragon[i][j - 1].size();
            for (int k = n - 1; k >= 0; k--) {
                dragon[i][j].push_back((dragon[i][j-1][k] + 1) % 4);
            }
            for (int k = 0; k < n; k++) {
                dragon[i][j].push_back(dragon[i][j-1][k]);
            }
        }
    }
}
void go(int x, int y, int d, int g) {
    _map[x][y] = 1;
    for (int i = 0; i <= g; i++) {
        for (int dir : dragon[d][i]) {
            x += dx[dir];
            y += dy[dir];
            _map[x][y] = 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    makeDragon();
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        go(x, y, d, g);
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (_map[i][j] && _map[i + 1][j] && _map[i][j + 1] && _map[i + 1][j + 1]) _count++;
        }
    }
    cout << _count << '\n';

    return 0;
}
