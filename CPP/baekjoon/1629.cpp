#include <bits/stdc++.h>

using namespace std;

long long A, B, C;
long long go(long long a, long long b) {
    if (b == 1) return a % C;

    long long result = go(a, b / 2);
    result = (result * result) % C;
    if (b % 2) result = result * a % C;
    return result;
}

int main() {
    cin >> A >> B >> C;

    cout << go(A, B);

    return 0;
}