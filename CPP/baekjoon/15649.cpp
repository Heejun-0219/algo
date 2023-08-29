#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool visited[10];

void solve(int count) {
    if (count == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[count] = i;
            solve(count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    solve(0);
    return 0;
}
