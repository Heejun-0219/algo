#include <iostream>
using namespace std;

int N, M;
int arr[10];

void solve(int count) {
    if (count == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (count == 0 || arr[count - 1] <= i){
            arr[count] = i;
            solve(count + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    solve(0);
    return 0;
}
