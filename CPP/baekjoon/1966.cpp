#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int> > Q;
        priority_queue<int> pq;

        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            Q.push(make_pair(i, priority));
            pq.push(priority);
        }

        int count = 0;
        while (!Q.empty()) {
            int idx = Q.front().first;
            int val = Q.front().second;
            Q.pop();
            if (pq.top() == val) { 
                pq.pop();
                ++count;
                if (idx == M) {
                    cout << count << "\n";
                    break;
                }
            } else {
                Q.push(make_pair(idx, val));
            }
        }
    }

    return 0;
}

// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// int main() {
//     int T;
//     cin >> T;
    
//     while(T--) {
//         int N, M, count = 0;
//         cin >> N >> M;
        
//         queue<pair<int, int>> q;
//         priority_queue<int> pq;
        
//         for(int i = 0; i < N; i++) {
//             int a;
//             cin >> a;
//             q.push({i, a});
//             pq.push(a);
//         }
        
//         while(!q.empty()) {
//             int idx = q.front().first;
//             int val = q.front().second;
//             q.pop();
            
//             if(pq.top() == val) {
//                 pq.pop();
//                 ++count;
                
//                 if(idx == M) {
//                     cout << count << '\n';
//                     break;
//                 }
//             } else {
//                 q.push({idx, val});
//             }
//         }
//     }
//     return 0;
// }
