#include <iostream>
using namespace std;
typedef long long ll;
ll n, m, a[1000004], k, maxValue, lo, hi, sum;
bool go(int money) {
    int cnt = 1;
    int tmp = money;
    for (size_t i = 0; i < n; i++)
    {
        if (money - a[i] < 0) {
            money = tmp;
            cnt++;
        }
        money -= a[i];
    }
    return cnt <= m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        maxValue = max(maxValue, a[i]);
        sum += a[i];
    }
    lo = maxValue; hi = sum;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (go(mid)) {
            hi = mid - 1;
            k = mid;
        }
        else lo = mid + 1;
    }
    cout << k << '\n';
    
    return 0;
}
