#include <iostream>
using namespace std;

int main(){
    string s;
    int arr[26] = {0, };
    cin >> s;

    // string 클래스  대문자 치환 
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            s[i] -= 32;
        }
    }

    int len = s.length();
    for (int i = 0; i < len; i++){
        arr[s[i] - 'A']++;
    }


    int max = 0;
    int index = 0;
    int flag = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        if (arr[i] > max){
            max = arr[i];
            index = i;
            flag = 0;
        }
        else if (arr[i] == max){
            flag = 1;
        }
    }

    if (flag == 1){
        cout << "?";
    }
    else{
        cout << (char)(index + 'A');
    }
    return 0;
}