#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<int> S;

    int index = 1;
    while (N--)
    {
        int num;
        cin >> num;

        while (S.size() && S.top() == index)
        {
            S.pop();
            index++;
        }        

        S.push(num);
    }

    while (S.size() && S.top() == index)
    {
        S.pop();
        index++;
    }    

    if (S.empty())
        cout << "Nice\n";
    else
        cout << "Sad\n";
    return 0;
}
