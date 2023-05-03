#include <iostream>
#include <string>
using namespace std;

int main(){
    string A, B, C;

    cin >> A >> B;

    int a_len = A.length();
    int b_len = B.length();
    int i = 0;
    while (a_len > 0 || b_len > 0)
    {
        int a = 0;
        int b = 0;
        if (a_len > 0) a = A[--a_len] - '0';
        if (b_len > 0) b = B[--b_len] - '0';
        int c = a + b + i;
        i = c / 10;
        c %= 10;
        C.insert(0, to_string(c));
    }
    
    if (i > 0) C.insert(0, to_string(i));
    cout << C << endl;
    return 0;
}