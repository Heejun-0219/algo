#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<int> S;

    int sel;
    while (N--)
    {
        cin >> sel;
        switch (sel)
        {
        case 1:
            int val; 
            cin >> val;
            S.push(val);
            break;
        case 2:
            if (!S.empty()) {
                cout << S.top() << '\n';
                S.pop();
            }
            else cout << "-1\n";
            break;
        case 3:
            cout << S.size() << '\n';
            break;
        case 4:
            cout << S.empty() << '\n';
            break;
        case 5:
            if (!S.empty()) cout << S.top() << '\n';
            else cout << "-1\n";
            break;
        default:
            break;
        }
    }

    return 0;
}