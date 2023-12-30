#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> c;
vector<int> v;
vector<int> val;
int ret = -987654321;

int return_val(int val, char a, int next) {
    if (a == '+') {
        return val + next;
    }
    else if (a == '-') {
        return val - next;
    }
    else if (a == '*') {
        return val * next;
    }
    else if (a == '/') {
        return val / next;
    }
    return 0;
}
void go(int here, int num) {
    if (here == v.size() - 1) {
        ret = max(ret, num);
        return;
    }

    go(here + 1, return_val(num, c[here], v[here + 1]));
    if (here + 2 <= v.size() - 1) {
        int tmp = return_val(v[here + 1], c[here + 1], v[here + 2]);
        go(here + 2, return_val(num, c[here], tmp));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        if (i % 2 == 1) {
            c.push_back(ch);
        }
        else {
            v.push_back(ch - '0');
        }
    }

    val.push_back(v[0]);
    go(0, v[0]);
    
    cout << ret << '\n';

    return 0;
}