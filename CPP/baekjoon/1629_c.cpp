#include <iostream>

using namespace std;

long long a, b, c;
long long go(long long A, long long B) {
    if (B == 1) {
        return A % c;
    }
    long long result = go(A, B / 2);
    result = (result * result) % c;
    if (B % 2) {
        result = (result * A) % c;
    }
    return result;
}
int main() {
    cin >> a >> b >> c;

    cout << go(a, b);

    return 0;
}
