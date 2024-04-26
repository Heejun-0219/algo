#include <iostream>
#include <stack>
#include <utility>

using namespace std;
typedef long long ll;
int n;
ll ret;
stack<pair<ll, ll>> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;

        cin >> tmp;
        
        int cnt = 1;
        while (s.size() && s.top().first <= tmp)
        {
            ret += s.top().second;
            if (s.top().first == tmp) {
                cnt = s.top().second + 1;
            }
            else {
                cnt = 1;
            }
            s.pop();
        }
        if (s.size()) ret++;
        s.push({tmp, cnt});
    }

    cout << ret << endl;

    return 0;
}
