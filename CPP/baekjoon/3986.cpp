#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    while (N--)
    {    
        stack<char> good_words;
        string s;
        cin >> s;

        if (s.size() & 1) {
            continue;
        }

        for (const char& c : s) {
            if (good_words.empty()) {
                good_words.push(c);
            }
            else if (good_words.top() == c) {
                good_words.pop();
            }
            else {
                good_words.push(c);
            }
        }

        if (good_words.empty()) {
            cnt++;
        }

    }

    cout << cnt << '\n';

    return 0;
}