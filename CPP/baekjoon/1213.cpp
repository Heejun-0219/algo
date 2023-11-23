#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    for (char a : s) cnt[a - 'A']++;

    int oddCount = 0;
    char oddChar = 0;
    string leftHalf = "", rightHalf = "";

    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            oddCount++;
            oddChar = i + 'A';
        }
        cnt[i] /= 2;

        for (int j = 0; j < cnt[i]; j++) {
            leftHalf += (char)(i + 'A');
        }
    }

    if (oddCount > 1) {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }

    rightHalf = leftHalf;
    reverse(rightHalf.begin(), rightHalf.end());

    string result = leftHalf;
    if (oddChar != 0) {
        result += oddChar;
    }
    result += rightHalf;

    cout << result << '\n';

    return 0;
}
