#include <bits/stdc++.h>

using namespace std;

int alpha_count[26];
// 65 - 90, 97 - 122
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string name;
    while (N--)
    {
        cin >> name;
        alpha_count[name[0] - 'a']++;
    }

    string answer = "";
    for (int i = 0; i < 26; i++) {
        if (alpha_count[i] >= 5) {
            answer += 'a' + i;
        }
    }
    
    if (answer.compare("")) {
        cout << answer << '\n';
    }
    else {
        cout << "PREDAJA" << '\n';
    }

    return 0;
}