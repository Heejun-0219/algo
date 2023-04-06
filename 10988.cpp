#include <iostream>
using namespace std;

int main(){
    string s;

    cin >> s;

    int len = s.length();
    for (int i = 0; i <  len / 2; i++){
        if (s[i] != s[len - 1 - i]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}