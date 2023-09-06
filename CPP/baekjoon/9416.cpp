#include <iostream>
#include <vector>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    vector<int> A(T);
    int max = 0;
    for (int i = 0; i < T; i++){
        cin >> A[i]; 
        if (max < A[i]) max = A[i];
    }

    vector<long long> p(max + 1, 1);
    for (int i = 4; i <= max; i++){
        p[i] = p[i - 2] + p[i - 3];
    }

    for (int i = 0; i < T; i++){
        cout << p[A[i]] << '\n';
    }    

    return 0;
}