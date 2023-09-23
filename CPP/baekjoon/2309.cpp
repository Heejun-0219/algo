#include <bits/stdc++.h>

#define MAX 9
#define ORIGIN 7

using namespace std;

vector<int> height(MAX);
vector<int> cur;

void display_kkoma(){
    sort(cur.begin(), cur.end());
    for (int i : cur){
        cout << i << '\n';
    }
}

int dfs(int index, int count) {
    if (count == ORIGIN) {
        int sum = accumulate(cur.begin(), cur.end(), 0);
        if (sum == 100) {
            display_kkoma();
            return 0;
        }
        return 1;
    }

    for (size_t i = index; i < MAX; i++)
    {
        cur.push_back(height[i]);
        if (dfs(i + 1, count + 1) == 0)
            return 0;
        cur.pop_back();
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (size_t i = 0; i < MAX; i++)
    {
        cin >> height[i];
    }
    
    dfs(0, 0);

    return 0;
}
