#include <bits/stdc++.h>

using namespace std;

int count_t[100];

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int fir, sec;
    for (int i = 0; i < 3; i++) {
        cin >> fir >> sec;
        for (int j = fir; j < sec; j++) count_t[j]++;
    }

    int result = 0;
    for (int i = 0; i < 100; i++) {
        if (count_t[i]) {
            if (count_t[i] == 1) result += A;
            else if (count_t[i] == 2) result += B * 2;
            else if (count_t[i] == 3) result += C * 3;
        }
    }

    cout << result;

    return 0;
}