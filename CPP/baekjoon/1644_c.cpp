#include <iostream>

using namespace std;

bool che[4000001];
int a[2000001];
int lo, hi, ret, sum, p;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (che[i]) continue;
        for (int j = 2*i; j <= n; j+=i) che[j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (!che[i]) a[p++] = i;
    }
    while (1)
    {
        if (sum >= n) sum -= a[lo++];
        else if (p == hi) break;
        else sum += a[hi++];
        if (sum == n) ret++;
    }
    cout << ret << endl;

    return 0;
}
