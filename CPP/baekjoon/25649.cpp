#include <iostream>
#include <vector>

using namespace std;

void dfs(int N, int M, int value, int step, vector<int> V){
    if (step == M){
        for (auto val : V)
            cout << val;
        cout << '\n';
    }

    cout << "value : " << value << " "; 
    V.push_back(value);
    for (int i = value + 1; i <= N; i++)
        dfs(N, M, i, step + 1, V);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> V;
    dfs(N, M, 1, 1, V);

    return 0;
}