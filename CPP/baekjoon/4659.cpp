#include <bits/stdc++.h>

using namespace std;

bool isVowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (true)
    {
        cin >> str;

        if (str.compare("end") == 0) 
            break;

        bool flag = false;
        bool vowel = false;
        int lcnt = 0;
        int rcnt = 0;
        bool is_vowel = false;

        for (int i = 0; i < str.size(); i++) {
            if (isVowel(str[i])) {
                lcnt++;
                rcnt = 0;
                is_vowel = true;
            }
            else {
                lcnt = 0;
                rcnt++;
            }

            if (lcnt >= 3 || rcnt >= 3) flag = true;

            if (i >= 1 && str[i - 1] == str[i]) {
                if (!(str[i] == 'e' || str[i] == 'o')) flag = true;
            }
        }
        if (!is_vowel) flag = true;

        if (flag) cout << "<" << str << "> is not acceptable.\n";
        else cout << "<" << str << "> is acceptable.\n";
    }
    
    return 0;
}