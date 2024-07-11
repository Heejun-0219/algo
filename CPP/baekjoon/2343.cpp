#include <iostream>
using namespace std;
int n, m, lo, hi, sum, maxValue, a[100004];
bool go(int capacity) {
    if (capacity < maxValue) return false;
    int cnt = 0;
    int tmp = capacity;
    for (int i = 0; i < n; i++) {
        if (capacity - a[i] < 0) {
            capacity = tmp;
            cnt++;
        }
        capacity -= a[i];
    }
    if (capacity != tmp) cnt++;
    return cnt <= m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        maxValue = max(maxValue, a[i]);
    }
    hi = sum;
    int ret = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (go(mid)) {
            hi = mid - 1;
            ret = mid;
        }
        else lo = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}
