#include <iostream>
using namespace std;
int n, a[100001], ret, cur;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cur = ret = a[0];
    for (int i = 1; i < n; i++) {
        cur = max(a[i], cur + a[i]);
        ret = max(cur, ret);
    }
    cout << ret << '\n'; 

    return 0;
}
