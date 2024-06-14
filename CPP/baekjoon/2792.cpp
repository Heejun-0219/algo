#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
long long n, m, ret = 987654321;
vector<long long> v;
bool go(long long candy) {
    int _cnt = 0;
    for (int i = 0; i < m; i++) {
        _cnt += ceil((double) v[i] / candy);
    }
    return n >= _cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    long long lo = 1, hi = 0;

    v.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        hi = max(hi, v[i]);
    }

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;

        if (go(mid)) {
            hi = mid - 1;
            ret = min(ret, mid);
        } 
        else lo = mid + 1;
    }
    cout << ret << '\n';

    return 0;
}
