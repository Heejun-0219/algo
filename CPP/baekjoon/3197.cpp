#include <bits/stdc++.h>
using namespace std;

int r, c, x, y;
char a[1504][1504];
int visited[1504][1504], swan_visited[1504][1504];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
queue<pair<int, int> > swan, swan_tmp, water, water_tmp;
int swanY, swanX;
int day;
string s;

void Qclear(queue<pair<int, int> > &q) {
    queue<pair<int, int> > tmp;
    swap(q, tmp);
}

void water_melting() {
    while (water.size())
    {
        y = water.front().first;
        x = water.front().second;
        water.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
            if (a[ny][nx] == 'X') {
                a[ny][nx] = '.';
                visited[ny][nx] = 1;
                water_tmp.push(make_pair(ny, nx));
            }
        }
    }
}

bool move_swan() {
    while (swan.size())
    {
        y = swan.front().first;
        x = swan.front().second;
        swan.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || swan_visited[ny][nx]) continue;
            swan_visited[ny][nx] = 1;
            if (a[ny][nx] == '.') swan.push(make_pair(ny, nx));
            else if (a[ny][nx] == 'X') swan_tmp.push(make_pair(ny, nx));
            else if (a[ny][nx] == 'L') return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            a[i][j] = s[j];
            if (a[i][j] == 'L') {
                swanY = i;
                swanX = j;
            }
            if (a[i][j] == '.' || a[i][j] == 'L') {
                visited[i][j] = 1;
                water.push(make_pair(i, j));
            }
        }
    }
    swan.push(make_pair(swanY, swanX));
    swan_visited[swanY][swanX] = 1;
    while (true)
    {
        if (move_swan()) break;
        water_melting();
        water = water_tmp;
        swan = swan_tmp;
        Qclear(water_tmp);
        Qclear(swan_tmp);
        day++;
    }
    cout << day << '\n';
    
    return 0;
}