#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> value(N + 1, 0);
    for (int i = 1; i <= N; i++){
        cin >> value[i];
    }

    vector<int> front(N + 1, 1);
    vector<int> back(N + 1, 1);

    for (int i = 2; i <= N; i++){
        for (int j = 1; j < i; j++){
            if (value[i] > value[j] && front[i] < front[j] + 1)
                front[i] = front[j] + 1;
        }
    }

    for (int i = N - 1; i >= 1; i--){
        for (int j = N; j > i; j--){
            if (value[i] > value[j] && back[i] < back[j] + 1)
                back[i] = back[j] + 1;
        }
    }

    vector<int> result(value.size(), 0);
    // for (size_t i = 1; i <= N; i++){
    //     result[i] = front[i] + back[i] - 1;
    // }
    transform(front.begin(), front.end(), back.begin(), result.begin(), plus<int>());

    // for (size_t i = 1; i < result.size(); ++i) {
    //     cout << result[i] << " ";
    // }

    cout << *max_element(result.begin() + 1, result.end()) - 1 << '\n';

    return 0;
}
