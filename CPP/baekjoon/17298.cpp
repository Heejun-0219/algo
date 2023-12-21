#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000004], cnt[1000004];
stack<int> s;
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;
    memset(cnt, -1, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (!s.empty() && a[s.top()] < a[i])
        {
            cnt[s.top()] = a[i];
            s.pop();
        }
        s.push(i);        
    }
    for (int i = 0; i < n; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}