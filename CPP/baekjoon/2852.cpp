#include <bits/stdc++.h>

using namespace std;

int score;

string cal_time(int team_time) {
    string min = "00" + to_string(team_time / 60);
    string sec = "00" + to_string(team_time % 60);

    return (min.substr(min.size() - 2, 2) + ":" + sec.substr(sec.size() - 2, 2));
}

int changeToInt(string str) {
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3));
}

void go(int &team, string goal, string pre_time) {
    team += (changeToInt(goal) - changeToInt(pre_time));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int A = 0;
    int B = 0;
    string pre_time;
    while (n--)
    {
        string team;
        string goal_time;

        cin >> team >> goal_time;

        if (score > 0) {
            go(A, goal_time, pre_time);
        }
        else if (score < 0) {
            go(B, goal_time, pre_time);
        }

        if (team == "1") {
            score++;
        }
        else score--;

        pre_time = goal_time;
        // cout << team << " " << min << " " << sec << '\n';
    }
    
    if (score > 0) {
        go(A, "48:00", pre_time);
    }
    else if (score < 0) {
        go(B, "48:00", pre_time);
    }


    cout << cal_time(A) << '\n' << cal_time(B);
    return 0;
}