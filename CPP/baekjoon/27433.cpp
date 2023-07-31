#include <iostream>

using namespace std;

long long Factual(int N){
    if (N == 1 || N == 0)
        return 1;
    return N * Factual(N - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    cout << Factual(N) << '\n';

    return 0;
}