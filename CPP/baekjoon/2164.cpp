#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    queue<int> Q;
    for (int i = 1; i <= N; i++) Q.push(i);

    while (Q.size() != 1)
    {
        if (!Q.empty())
            Q.pop();
        if (!Q.empty() && Q.size() != 1){
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    cout << Q.front() << endl;

    return 0;
}

// #include <iostream>
// #include <queue>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int N;
//     cin >> N;

//     queue<int> Q;
//     for (int i = 1; i <= N; ++i) {
//         Q.push(i);
//     }

//     while (Q.size() > 1) {
//         Q.pop();
//         Q.push(Q.front());
//         Q.pop();
//     }

//     cout << Q.front() << '\n';

//     return 0;
// }
