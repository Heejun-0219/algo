#include <iostream>
using namespace std;

void putnbr(long N, int B){
    if (N == 0) return;
    putnbr(N / B, B);
    if (N % B < 10) {
        cout << N % B;
    } else {
        cout << (char)(N % B - 10 + 'A');
    }
}

int main(){
    long N;
    int B;

    cin >> N >> B;
    putnbr(N, B);
    return 0;
}