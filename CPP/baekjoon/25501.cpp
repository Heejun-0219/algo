#include <iostream>
#include <string.h>

using namespace std;

int count_re = 0;

int recursion(string s, int l, int r){
    count_re++;
    if(l >= r) 
        return 1;
    else if (s[l] != s[r]) return 0;
    else 
        return recursion(s, l+1, r-1);
}

int isPalindrome(string s){
    return recursion(s, 0, s.size() - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    string str;
    while (T--)
    {
        count_re = 0;

        cin >> str;
        cout << isPalindrome(str) << " " << count_re << endl;
    }
    
    return 0;
}

// #include <iostream>
// #include <string>

// using namespace std;

// int recursion(const string& s, int l, int r, int& counter){
//     counter++;
//     if(l >= r) return 1;
//     else if(s[l] != s[r]) return 0;
//     else return recursion(s, l+1, r-1, counter);
// }

// pair<int, int> isPalindrome(const string& s){
//     int counter = 0;
//     int result = recursion(s, 0, s.size()-1, counter);
//     return make_pair(result, counter);
// }

// int main() {
//     int T;
//     cin >> T;
//     for (int i = 0; i < T; i++) {
//         string S;
//         cin >> S;
//         pair<int, int> result = isPalindrome(S);
//         cout << result.first << " " << result.second << endl;
//     }
//     return 0;
// }
