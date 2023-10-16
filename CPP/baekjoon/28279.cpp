#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    deque<int> De;

    int input, val;
    while (N--)
    {
        cin >> input;

        switch (input)
        {
        case 1:
            cin >> val;
            De.push_front(val);
            break;
        case 2:
            cin >> val;
            De.push_back(val);
            break;
        case 3:
            if (De.empty() == 0) {
                cout << De.front() << '\n';
                De.pop_front();
            }
            else cout << "-1\n";
            break;
        case 4:
            if (De.empty() == 0) {
                cout << De.back() << '\n';
                De.pop_back();
            }
            else cout << "-1\n";
            break;
        case 5:
            cout << De.size() << '\n';
            break;
        case 6:
            cout << De.empty() << '\n';
            break;
        case 7:
            if (De.empty() == 0) 
                cout << De.front() << '\n';
            else 
                cout << "-1\n";
            break;
        case 8:
            if (De.empty() == 0)
                cout << De.back() << '\n';
            else 
                cout << "-1\n";
            break;
        default:
            break;
        }
        val = 0;
    }    

    return 0;
}