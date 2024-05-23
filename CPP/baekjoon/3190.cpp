#include <iostream>
#include <vector>

using namespace std;

int n, k, l;
int a[101][101];
vector<pair<int, char> > v;
vector<pair<int, int> > snake;
long long game_time;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int y_head, x_head;
int time_index, direction;

void user_input() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        a[y-1][x-1] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int time;
        char direct;
        cin >> time >> direct;

        v.push_back(make_pair(time, direct));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    user_input();

    a[0][0] = 2;
    snake.push_back(make_pair(0, 0));
    while (true)
    {
        if (game_time == v[time_index].first) {
            if (v[time_index++].second == 'D') direction++;
            else direction--;

            if (direction == -1) direction = 3; 

            direction %= 4;
        }

        int ny = y_head + dy[direction];
        int nx = x_head + dx[direction];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
        if (a[ny][nx] == 2) break;

        if (a[ny][nx] == 0) {
            a[snake[0].first][snake[0].second] = 0;           
            snake.erase(snake.begin(), snake.begin() + 1);
        }
        a[ny][nx] = 2;
        snake.push_back(make_pair(ny, nx));

        y_head = ny;
        x_head = nx;

        game_time++;
    }
    cout << game_time + 1 << '\n';

    return 0;
}
