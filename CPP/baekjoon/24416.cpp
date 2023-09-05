#include <iostream>

using namespace std;

long long fin[41];
int g_re_count, g_di_count;

long long re_fib(int N) {
    if (N == 1 || N == 2){
        g_re_count++;    
        return 1;
    } 
    else return (re_fib(N - 1) + re_fib(N - 2));
}

long long di_fib(int N) {
    int index = 1;

    if (N >= 1) {
        index++;
        fin[1] = 1;
    }
    if (N >= 2) {
        index++;
        fin[2] = 1;
    }

    int i;
    for (i = index; i <= N; i++, g_di_count++) {
        fin[i] = fin[i-1] + fin[i-2];
    }

    return fin[i - 1]; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    re_fib(N);
    di_fib(N);

    cout << g_re_count << " " << g_di_count;

    return 0;
}