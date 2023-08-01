#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void drawStars(int n, int x, int y) {
    if ((x / n) % 3 == 1 && (y / n) % 3 == 1) {
        cout << ' ';
    } else {
        if (n / 3 == 0)
            cout << '*';
        else
            drawStars(n / 3, x, y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            drawStars(N, i, j);
        }
        cout << '\n';
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<vector<char>> stars;

// void solve(int y, int x, int num) {
//     if(num == 1) {
//         stars[y][x] = '*';
//         return;
//     }

//     int div = num/3;
//     for(int i = 0; i < 3; i++) {
//         for(int j = 0; j < 3; j++) {
//             if(i == 1 && j == 1)
//                 continue;
//             solve(y + (i*div), x + (j*div), div);
//         }
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     stars = vector<vector<char>>(n, vector<char>(n, ' '));
//     solve(0, 0, n);
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cout << stars[i][j];
//         }
//         cout << "\n";
//     }
//     return 0;
// }
