#include <iostream>
#include <string>
#include <set>

std::set<std::string> substr_set;

void getSet_substr(std::string s, int start, int len){
    if (len){
        for (int i = start; i <= s.length() - len; i++){
            substr_set.insert(s.substr(i, len));
        }
        getSet_substr(s, start, len - 1);
    }
    else return;
}

int main(){
    std::string input;
    std::cin >> input;

    getSet_substr(input, 0, input.length());

    std::cout << substr_set.size();
    return 0;
}

// #include <iostream>
// #include <unordered_set>
// using namespace std;

// int main() {
//     string S;
//     cin >> S;

//     int n = S.length();
//     unordered_set<string> substrings;

//     for (int i = 0; i < n; i++) {
//         string substring = "";
//         for (int j = i; j < n; j++) {
//             substring += S[j];
//             substrings.insert(substring);
//         }
//     }

//     int count = substrings.size() - 1;  // 빈 문자열을 제외하기 위해 1을 빼줌
//     cout << count << endl;

//     return 0;
// }
