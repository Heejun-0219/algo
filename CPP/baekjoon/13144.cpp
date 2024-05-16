#include <iostream>
#include <vector>
using namespace std;
long long ret, s, e, a[100001], cnt[100001], n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (e < n)
    {
        if (!cnt[a[e]]) {
            cnt[a[e]]++;
            e++;
        }
        else {
            ret += (e - s);
            cnt[a[s]]--;
            s++;
        }
    }
    ret += (long long) (e - s) * (e - s + 1) / 2;
    cout << ret << endl;    

    return 0;
}
