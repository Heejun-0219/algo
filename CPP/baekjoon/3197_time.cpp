#include <bits/stdc++.h>
using namespace std;

int r, c;
char v[1504][1504];
int visited[1504][1504];
vector<pair<int, int> > water, swan;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
bool flag = false;
int day;

void print_map() {
    cout << "-----------------------------\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void print_water() {
    for (pair<int, int> p : water) {
        cout << p.first << " " << p.second << '\n';
    }
}

void dfs(int y, int x) {
    if (flag) return ;

    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (visited[ny][nx]) continue;

        if (ny == swan[1].first && nx == swan[1].second) {
            flag = true;
            return ;
        }

        if (v[ny][nx] == '.')
            dfs(ny, nx);
    }
}

bool meeting_swan() {
    memset(visited, 0, sizeof(visited));
    dfs(swan[0].first, swan[0].second);
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            if (v[i][j] == '.') water.push_back(make_pair(i, j));
            else if (v[i][j] == 'L') swan.push_back(make_pair(i, j));
        }
    }

    while (!meeting_swan())
    {
        day++;

        vector<pair<int, int> > tmp;
        for (pair<int, int> p : water) {
            for (int i = 0; i < 4; i++) {
                int ny = p.first + dy[i];
                int nx = p.second + dx[i];

                if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                if (v[ny][nx] == 'X') {
                    tmp.push_back(make_pair(ny, nx));
                    v[ny][nx] = '.';
                }
            }
        }
        water = tmp;
    }

    cout << day << '\n';

    return 0;
}