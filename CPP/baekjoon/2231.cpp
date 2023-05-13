#include <iostream>
using namespace std;

int get_sub(int value){
    int v = 0;
    while (value != 0) {
        v += value % 10;
        value /= 10;
    }
    return v;
}

int main(){
    int N;
    cin >> N;

    int M = 0;
    for (int i = 1; i < N; i++) {
        int sub = get_sub(i);
        if (i + sub == N) {
            M = i;
            break;
        }
    }
    
    cout << M << endl;
    return 0;
}
