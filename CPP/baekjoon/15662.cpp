#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, k;
vector<int> pos;
vector<vector<int>> gears;
vector<bool> visited;

void rotate_gear(int idx, int direction) {
    if (direction == 1) {
        pos[idx] = (pos[idx] + 7) % 8;
    } else {
        pos[idx] = (pos[idx] + 1) % 8;
    }
}

void dfs(int gear_idx, int direction) {
    visited[gear_idx] = true;
    int current_right = (pos[gear_idx] + 2) % 8;
    int current_left = (pos[gear_idx] + 6) % 8;
    int left_gear_idx = gear_idx - 1;
    if (left_gear_idx >= 0 && !visited[left_gear_idx]) {
        int left_right = (pos[left_gear_idx] + 2) % 8;
        if (gears[gear_idx][current_left] != gears[left_gear_idx][left_right]) {
            dfs(left_gear_idx, -direction);
        }
    }

    int right_gear_idx = gear_idx + 1;
    if (right_gear_idx < t && !visited[right_gear_idx]) {
        int right_left = (pos[right_gear_idx] + 6) % 8;
        if (gears[gear_idx][current_right] != gears[right_gear_idx][right_left]) {
            dfs(right_gear_idx, -direction);
        }
    }

    rotate_gear(gear_idx, direction);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    pos.resize(t, 0);
    gears.resize(t, vector<int>(8));

    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            gears[i][j] = s[j] - '0';
        }
    }

    cin >> k;
    while (k--) {
        int gear_idx, direction;
        cin >> gear_idx >> direction;
        --gear_idx;

        visited.assign(t, false);
        dfs(gear_idx, direction);
    }

    int count = 0;
    for (int i = 0; i < t; ++i) {
        if (gears[i][pos[i]] == 1) {
            ++count;
        }
    }
    cout << count << '\n';

    return 0;
}
