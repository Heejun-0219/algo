#include <iostream>

using namespace std;

bool is_safe(int **map, int x, int y, int N){
    for (int i = 0; i < x; i++){
        if (map[i][y] == 1)
            return false;
    }

    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--){
        if (map[i][j] == 1)
            return false;
    }

    for (int i = x, j = y; i >= 0 && j < N; i--, j++){
        if (map[i][j] == 1)
            return false;
    }

    return true;
}

void Nqueen(int** map, int step, int N, int &count){
    if (N == step) {
        count++;
        return;
    }

    for (int i = 0; i < N; i++){
        if (map[step][i] == 0 && is_safe(map, step, i, N)) {
            map[step][i] = 1;
            Nqueen(map, step + 1, N, count);
            map[step][i] = 0;
        }
    }
}

int main(){
    int N;
    cin >> N;

    int** map = new int*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[N];
        fill(map[i], map[i] + N, 0);
    }

    int count = 0;
    Nqueen(map, 0, N, count);

    cout << count << endl;

    for (int i = 0; i < N; i++) {
        delete[] map[i];
    }
    delete[] map;

    return 0;
}
