#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int arr[51][51];
int visited[51][51];
int cnt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N || arr[ny][nx] == 0) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> M >> N >> K;

        cnt = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] =  1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 0 && arr[i][j] == 1) {
                    cnt++;
                    dfs(j, i);
                }
            }
        }

        cout << cnt << '\n';
    }    
    return 0;
}