#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> s;
int ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    char c;
    s.push(-1);
    for (int i = 0; i < n; i++) {
        cin >> c;

        if (c == '(') {
            s.push(i);
        }
        else if (c == ')') {
            s.pop();
            if (s.size()) {
                ret = max(i - s.top(), ret);
            }
            else {
                s.push(i);
            }
        }
    }

    cout << ret << endl;

    return 0;
}
