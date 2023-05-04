#include <iostream>
using namespace std;

int main(){
    int N;

    cin >> N;

    int cnt = 2;
    int i;
    while (N != 1)
    {
        for (i = cnt; i <= N; i++){
            if (N % i == 0) {
                N /= i;
                cout << i << endl;
                break;
            }
        }
        cnt = i;
    }

    return 0;
}