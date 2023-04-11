#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    bool paper[101][101] = {false,};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = y; j < y + 10; j++) {
            for (int k = x; k < x + 10; k++) {
                paper[j][k] = true;
            }
        }
    }
    int area = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (paper[i][j]) {
                area++;
            }
        }
    }
    cout << area << endl;
    return 0;
}
