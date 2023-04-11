#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int checkBase(char c, char base[], int size){
    for (int i = 0; i < size; i++){
        if (c == base[i]){
            return 1;
        }
    }
    return 0;
}

int checkAlpha(const char *s, string alpha[], int size){
    int len = strlen(s);
    for (int i = 0; i < size; i++){
        if (strncmp(s, alpha[i].c_str(), alpha[i].length()) == 0){
            return alpha[i].length();
        }
    }
    return 1;
}

int main(){
    string s;
    char base[6]= {'c', 'd', 'l', 'n', 's', 'z'};
    string alpha[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int count = 0;

    cin >> s;

    int len = s.length();
    for (int i = 0; i < len; i++){
        if (checkBase(s[i], base, sizeof(base)/sizeof(base[0]))){
            i += checkAlpha(&s[i], alpha, sizeof(alpha)/sizeof(alpha[0])) - 1;
        }
        count++;
    }
    cout << count;
    return 0;
}
