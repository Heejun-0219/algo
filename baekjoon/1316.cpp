#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt = 0;
    string s;
    char alpha[26];
    int flag = 0;
    while (n--)
    {
        cin >> s;
        int len = s.length();

        memset(alpha, 0, sizeof(alpha));
        flag = 0;
        alpha[s[0] - 'a']++; 

        for (int i = 1; i < len; i++){
            if (s[i] != s[i - 1])
                if (alpha[s[i] - 'a'] != 0) {
                    flag = 1;
                    break;
                }
            alpha[s[i] - 'a']++;
        }
        if (flag == 0)
            cnt++;
    }
    cout << cnt;
    return 0;
}