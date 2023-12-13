#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a;
    while (n--)
    {
        cin >> a;
        int ret2 = 0;
        int ret5 = 0;
        for (int j = 2; j <= a; j*=2) {
            ret2 += a / j;
        }
        for (int j = 5; j <= a; j*=5) {
            ret5 += a / j;
        }
        cout << min(ret2, ret5) << '\n';
    }   

    return 0;
}