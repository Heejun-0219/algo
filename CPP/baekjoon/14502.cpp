#include <bits/stdc++.h>

using namespace std;

int N, M;
int vis_map[8][8];
vector<pair<int, int> > wallList;
vector<pair<int, int> > virusList;
int map_cnt;
int visited[8][8];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (vis_map[ny][nx] == 1 || visited[ny][nx]) continue;

        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return;
}

int sol() {
    for (int i = 0; i < N; i++) {
        memset(visited[i], 0, sizeof(visited[i]));
    }

    for (int i = 0; i < virusList.size(); i++) {
        visited[virusList[i].first][virusList[i].second] = 1;
        dfs(virusList[i].first, virusList[i].second);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis_map[i][j] == 0 && visited[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void cal_vir() {
    for (int i = 2; i < wallList.size(); i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 0; k < j; k++) {
                vis_map[wallList[i].first][wallList[i].second] = 1;
                vis_map[wallList[j].first][wallList[j].second] = 1;
                vis_map[wallList[k].first][wallList[k].second] = 1;
                map_cnt = max(map_cnt, sol());
                vis_map[wallList[i].first][wallList[i].second] = 0;
                vis_map[wallList[j].first][wallList[j].second] = 0;
                vis_map[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
}

void init_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val;
            cin >> val;

            if (val == 0) {
                wallList.push_back(make_pair(i, j));
            }
            else if (val == 1) {
                vis_map[i][j] = 1;
            }
            else if (val == 2) {
                vis_map[i][j] = 2;
                virusList.push_back(make_pair(i, j));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M;

    init_map();

    cal_vir();

    cout << map_cnt << '\n';

    return 0;
}