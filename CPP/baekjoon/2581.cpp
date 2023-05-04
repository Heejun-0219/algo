#include <iostream>
using namespace std;

int check_prime(int n){
    int i;
    if (n == 2 || n == 3) return 1;
    for (i = 2; i <= n/2; i++)
    {
        if (n % i == 0) {
            break;
        }
        else if (i == n/2) return 1;
    }
    return 0;
}

int main(){
    int M, N;

    cin >> M >> N;

    int c = -1;
    int fir = 0;
    for (int i = M; i <= N; i++)
    {
        if (check_prime(i)){
            if (c == -1){
                fir = c = i;
            }
            else c += i;
        }
        else continue;
    }
    cout << c << endl;
    if (fir) cout << fir << endl;
    return 0;
}