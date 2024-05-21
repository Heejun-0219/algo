#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int INF = 987654321;
int a[21][21], n;
int _min = INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> ind(n, 0);
    for (int i = n / 2; i < n; i++) {
        ind[i] = 1;
    }

    do
    {
        vector<int> team1, team2;
        int first_team = 0, second_team = 0;

        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == 1) {
                team1.push_back(i);
            }
            else {
                team2.push_back(i);
            }
        }

        for (int i = 0; i < team1.size(); i++) {
            for (int j = i + 1; j < team1.size(); j++) {
                first_team += a[team1[i]][team1[j]];
                first_team += a[team1[j]][team1[i]];
            }
        }
        for (int i = 0; i < team2.size(); i++) {
            for (int j = i + 1; j < team2.size(); j++) {
                second_team += a[team2[i]][team2[j]];
                second_team += a[team2[j]][team2[i]];
            }
        }

        _min = min(_min, abs(first_team - second_team));
    } while (next_permutation(ind.begin(), ind.end()));
    
    cout << _min;

    return 0;
}
