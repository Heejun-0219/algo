#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, C;
    cin >> N >> C;

    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    int left = 1;
    int right = A[N - 1] - A[0];
    int max_len = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int count = 1;
        int pre_house = A[0];

        for (int i = 1; i < N; i++){
            if (A[i] - pre_house >= mid){
                pre_house = A[i];
                count++;
            }
        }

        if (count >= C){
            max_len = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    cout << max_len;

    return 0;
}