#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v, oper_seq;
int oper[4];
long long gmin = 1e9, gmax = -1e9;

void cal() {
    long long _cur = v[0];
    for (int i = 0; i < n - 1; i++) {
        if (oper_seq[i] == 0) {
            _cur += v[i + 1];
        }
        else if (oper_seq[i] == 1) {
            _cur -= v[i + 1];
        }
        else if (oper_seq[i] == 2) {
            _cur *= v[i + 1];
        }
        else if (oper_seq[i] == 3) {
            if (v[i + 1] == 0) return;
            _cur /= v[i + 1];
        }
    }

    gmin = min(gmin, _cur);
    gmax = max(gmax, _cur);
}

void dfs(int index) {
    if (index == n - 1) {
        cal();
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (oper[i] > 0) {
            oper[i]--;
            oper_seq.push_back(i);
            dfs(index + 1);
            oper_seq.pop_back();
            oper[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    dfs(0);

    cout << gmax << endl << gmin << endl;
}
