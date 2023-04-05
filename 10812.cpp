#include <iostream>
#include <unistd.h>
using namespace std;

int n, m;
int basket[101];
int tmp[101];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        basket[i] = i;
    }
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        for (int idx = i; idx <= j; idx++) {
            // i - j만큼 반복문 실행, j - k + 1만큼씩 인덱스 뒤로 이동
            // 이때 인덱스가 k를 넘어가는 경우에는 k - i만큼씩 인덱스 이동
            if (idx >= k) {
                tmp[idx - k + i] = basket[idx];
            } else {
                tmp[idx + j - k + 1] = basket[idx];
            }
        }
        for (int idx = i; idx <= j; idx++) {
            basket[idx] = tmp[idx];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << basket[i] << " ";
    }
    cout << endl;
    return 0;
}
