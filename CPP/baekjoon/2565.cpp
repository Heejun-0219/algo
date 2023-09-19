#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int> > A(N);
    for (int i = 0; i < N; i++){ 
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    // for(auto a : A){
    //     cout << a.second << " ";
    // }

    vector<int> lis(N, 1);

    for (int i = 1; i < N; i++){
        for (int j = 0; j < i; j++){
            if (lis[i] < lis[j] + 1 && A[i].second > A[j].second)
                lis[i] = lis[i] + 1;
        }
    }

    int lis_max = *max_element(lis.begin(), lis.end());
    cout << N - lis_max;

    return 0;
}