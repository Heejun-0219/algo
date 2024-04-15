#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, k, character = 1;
vector<int> s;
int maxCount = 0;
void countCollectWord(int value) {
    int cnt = 0;
    for (int word : s) {
        if (word && (word & value) == word) cnt++;
    }

    maxCount = max(maxCount, cnt);
}
void dfs(int index, int cnt, int value) {
    if (cnt >= k) {
        countCollectWord(value);
        return;
    }

    for (int i = index; i < 26; i++) {
        if (value & (1 << i)) continue;
        dfs(i + 1, cnt + 1, value | (1 << i));
    }
}
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        int bits = 0;
        for (int j = 0; j < tmp.size(); j++) {
            bits |= (1 << tmp[j] - 65);
        }
        s.push_back(bits);
    }

    if (k <= 3) {
        cout << 0 << endl;
        return 0;
    }

    character |= (1 << 2);
    character |= (1 << 8);
    character |= (1 << 13);
    character |= (1 << 19);

    dfs(1, 5, character);
    
    cout << maxCount << endl;

    return 0;
}
