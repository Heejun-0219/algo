#include <iostream>

using namespace std;

long long Fibbonaci(int n, long long first, long long second){
    if (n == 0)
        return first;
    if (first == 0 && second == 1)
        return Fibbonaci(n - 1, 1, 1);
    return Fibbonaci(n - 1, second, first + second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cout << Fibbonaci(n, 0, 1) << '\n';

    return 0;
}