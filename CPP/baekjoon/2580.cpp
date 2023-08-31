#include <iostream>
#include <unistd.h>

using namespace std;

void print_map(int map[9][9]) {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

bool demo_num(int map[9][9], int x, int y, int value){
    for (int i = 0; i < 9; i++){
        if (map[x][i] == value)
            return false;
    }

    for (int i = 0; i < 9; i++){
        if (map[i][y] == value)
            return false;
    }

    x /= 3;
    x *= 3;
    y /= 3;
    y *= 3;
    for (int i = x; i < x + 3; i++){
        for (int j = y; j < y + 3; j++){
            if (map[i][j] == value)
                return false;
        }
    }

    return true;
}

bool bt(int map[9][9], int zero_count) {
    if (zero_count == 0) {
        print_map(map);
        return true;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (map[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (demo_num(map, i, j, k)) {
                        map[i][j] = k;
                        if (bt(map, zero_count - 1)) { 
                            return true; 
                        }
                        map[i][j] = 0;
                    }
                }
                return false; 
            }
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int map[9][9];
    int zero_count = 0;

    for (int i = 0, j = 0; i < 10; i++) {
        if (i == 9) {
            j++;
            i = 0;
            if (j == 9)
                break;
        }
        cin >> map[j][i];
        if (map[j][i] == 0)
            zero_count++;
    }

    bt(map, zero_count);

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int board[9][9];

// bool isValid(int row, int col, int num) {
//     for (int x = 0; x < 9; x++) {
//         if (board[row][x] == num || board[x][col] == num || board[3*(row/3) + x/3][3*(col/3) + x%3] == num) {
//             return false;
//         }
//     }
//     return true;
// }

// bool solveSudoku() {
//     int row = -1;
//     int col = -1;
//     bool isEmpty = true;
//     for (int i = 0; i < 9; i++) {
//         for (int j = 0; j < 9; j++) {
//             if (board[i][j] == 0) {
//                 row = i;
//                 col = j;
//                 isEmpty = false;
//                 break;
//             }
//         }
//         if (!isEmpty) {
//             break;
//         }
//     }

//     if (isEmpty) {
//         return true;
//     }

//     for (int num = 1; num <= 9; num++) {
//         if (isValid(row, col, num)) {
//             board[row][col] = num;
//             if (solveSudoku()) {
//                 return true;
//             }
//             board[row][col] = 0;
//         }
//     }
//     return false;
// }

// int main() {
//     for (int i = 0; i < 9; i++) {
//         for (int j = 0; j < 9; j++) {
//             cin >> board[i][j];
//         }
//     }

//     if (solveSudoku()) {
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 cout << board[i][j] << " ";
//             }
//             cout << endl;
//         }
//     } else {
//         cout << "No solution exists" << endl;
//     }
//     return 0;
// }
