#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    stack<int> S;
    queue<char> Q;
    int flag = true;

    int n;
    cin >> n;

    int index = 1;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;

        if (index == val){
            // cout << "push:" << index << endl;
            S.push(index++);
            Q.push('+');
        }

        if (index < val){
            while (index <= val){
                // cout << "push:" << index << endl;
                S.push(index++);
                Q.push('+');
            }
        }
        
        if (!S.empty() && S.top() == val){
                // cout << "pop:" << S.top() << endl;
                S.pop();
                Q.push('-');
        }
        else {
                flag = false;
                cout << "NO" << endl;
                break;
        }
        // cout << "index : " << index << endl;
    }
    
    while (flag && !Q.empty())
    {
        cout << Q.front() << endl;
        Q.pop();
    }    

    return 0;
}

// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;

//     vector<int> seq(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> seq[i];
//     }

//     stack<int> S;
//     vector<char> ans;
//     int num = 1;
//     for (int i = 0; i < n; ++i) {
//         while (num <= seq[i]) {
//             S.push(num++);
//             ans.push_back('+');
//         }
//         if (!S.empty() && S.top() == seq[i]) {
//             S.pop();
//             ans.push_back('-');
//         } else {
//             cout << "NO";
//             return 0;
//         }
//     }

//     for (char c : ans) {
//         cout << c << '\n';
//     }

//     return 0;
// }
