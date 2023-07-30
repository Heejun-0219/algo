#include <iostream>
#include <deque>
#include <vector>
#include <unistd.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> Q;
    int N, M;
    cin >> N >> M;

    vector<int> V;
    int index;
    for (int i = 0; i < M; i++){
        cin >> index;
        V.push_back(index);
    }

    for (int i = 0; i < N; i++){
        Q.push_back(i + 1);
    }

    int count = 0;
    index = 0;
    while (true)
    {
        if (index >= M){
            cout << count << '\n';
            break;
        }
        if (Q.front() == V[index]){
            Q.pop_front();
            index++;
        }
        else {
            deque<int> cal_l = Q;
            deque<int> cal_r = Q;
            int left, right;
            int left_count = 0;
            int right_count = 0;
            while (true)
            {
                left = cal_l.front();
                if (left != V[index]){
                    cal_l.pop_front();
                    cal_l.push_back(left);
                    left_count++;
                }
                else {
                    count += left_count;
                    Q = cal_l;
                    break;
                }

                right = cal_r.front();
                if (right != V[index]){
                    right = cal_r.back();
                    cal_r.pop_back();
                    cal_r.push_front(right);
                    right_count++;
                }
                else {
                    count += right_count;
                    Q = cal_r;
                    break;
                }
            }
        }
    }

    return 0;
}

// #include <iostream>
// #include <deque>
// #include <vector>

// using namespace std;

// void rotate_deque(deque<int>& dq, int direction, int& count) {
//     if(direction > 0) {
//         dq.push_back(dq.front());
//         dq.pop_front();
//     } else {
//         dq.push_front(dq.back());
//         dq.pop_back();
//     }
//     count++;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int N, M;
//     cin >> N >> M;

//     vector<int> V(M);
//     deque<int> Q(N);
//     for(int i = 0; i < N; ++i) Q[i] = i + 1;
//     for(int i = 0; i < M; ++i) cin >> V[i];

//     int count = 0;
//     int target_index = 0;

//     while (true) {
//         if (target_index >= M){
//             cout << count << '\n';
//             break;
//         }

//         if (Q.front() == V[target_index]){
//             Q.pop_front();
//             target_index++;
//         } else {
//             // calculate cost of rotation in both directions
//             int left_count = 0, right_count = 0;
//             deque<int> cal_l = Q, cal_r = Q;

//             while (cal_l.front() != V[target_index]) rotate_deque(cal_l, 1, left_count);
//             while (cal_r.front() != V[target_index]) rotate_deque(cal_r, -1, right_count);

//             // rotate the original queue in the cheaper direction
//             if(left_count <= right_count) {
//                 Q = cal_l;
//                 count += left_count;
//             } else {
//                 Q = cal_r;
//                 count += right_count;
//             }
//         }
//     }

//     return 0;
// }
