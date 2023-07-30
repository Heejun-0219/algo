// #include <iostream>
// #include <string>
// #include <deque>

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int T;
//     cin >> T;

//     if (T > 100) return -1;

//     string str;
//     deque<int> Q;
//     int Q_size;
//     string Q_str;
//     while (T--)
//     {
//         cin >> str >> Q_size;
//         cin.ignore();
//         getline(cin, Q_str);

//         int index = 0;
//         while (Q_str[index])
//         {
//             if (isdigit(Q_str[index])){
//                 Q.push_back(Q_str[index]);
//                 cout << Q_str[index];
//             }
//             index++;
//         }
    
//         index = 0;
//         while (str[index])
//         {
//             if (str[index] == 'R'){
//                 int Q_size = Q.size();
//                 while (Q_size--)
//                 {
//                     Q.push_back(Q.front());
//                     Q.pop_front();
//                 }
//             }
//             else if (str[index] == 'D'){
//                 if (Q.size() > 0)
//                     Q.pop_front();
//                 else {
//                     cout <<  "error\n";
//                     break;
//                 }
//             }
//             else {
//                 return -1;
//             }
//         }
        
//         cout << "[";
//         while (Q.size())
//         {
//             cout << Q.front();
//             Q.pop_front();
//             if (Q.size())
//                 cout << ",";
//         }
//         cout << "]";
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string p, arr, tmp;
        int n;
        deque<int> dq;
        bool reverseFlag = false;

        cin >> p >> n >> arr;

        for (auto ch : arr) {
            if (isdigit(ch)) {
                tmp += ch;
            }
            else {
                if (!tmp.empty()) {
                    dq.push_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }

        for (auto func : p) {
            if (func == 'R') {
                reverseFlag = !reverseFlag;
            }
            else if (func == 'D') {
                if (dq.empty()) {
                    cout << "error\n";
                    goto nextTest;
                }

                reverseFlag ? dq.pop_back() : dq.pop_front();
            }
        }

        cout << '[';
        while (!dq.empty()) {
            if (reverseFlag) {
                cout << dq.back();
                dq.pop_back();
            } else {
                cout << dq.front();
                dq.pop_front();
            }
            
            if (!dq.empty()) {
                cout << ',';
            }
        }
        cout << "]\n";

        nextTest:;
    }

    return 0;
}
