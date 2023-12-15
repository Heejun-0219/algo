#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int val = 666;; val++) {
        if (to_string(val).find("666") != string::npos) n--;
        if (n == 0) {
            cout << val;
            break;
        }
    }    

    return 0;
}