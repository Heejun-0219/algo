#include <bits/stdc++.h>
using namespace std;

int k;
char a[11], arr_ch[11];
int idx, cnt;

void print_arr() {
    for (int i = 0; i < k + 1; i++) {
        cout << arr_ch[i];
    }
    cout << '\n';
}

void len_cnt(int here, char ch, int op) {
    if (here > k || a[here] != ch) {
        arr_ch[here] = idx + '0';
        idx += op;
    } 
    else {
        len_cnt(here + 1, ch, op);
        cnt++;
        arr_ch[here] = idx + '0';
        idx += op;
    }
}

void dfs(int here, char ch, int op) {
    if (here >= k) {
        arr_ch[here] = idx + '0';
        print_arr();
        memset(arr_ch, 0, sizeof(arr_ch));
        return;
    }

    if (a[here] == ch) {
        arr_ch[here] = idx + '0';
        idx += op;
    }
    else {
        cnt = 0;
        len_cnt(here, a[here], op);
        here += cnt;
    }
    dfs(here + 1, ch, op);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    idx = 9;
    dfs(0, '>', -1);
    idx = 0;
    dfs(0, '<', 1);

    return 0;
}