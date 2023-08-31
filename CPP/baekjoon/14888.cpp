#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int g_max = -1000000000;
int g_min = 1000000000;

long get_val(vector<int> A, int index, int op, long value) {
    if (index == 0)
        value = A[index];
    int a = A[index + 1];

    switch (op)
    {
    case 0:
        value += a;
        break;
    case 1:
        value -= a;
        break;
    case 2:
        value *= a;
        break;
    case 3:
        if (value < 0) {
            value = -((-value) / a);
        } else {
            value /= a;
        }
        break;
    default:
        break;
    }
    return value;
}

void bt(vector<int> A, vector<int> op,int index, long value){
    if (index == A.size() - 1) {
        if (value > g_max) g_max = value;
        if (value < g_min) g_min = value;
        return ;
    }

    for (int i = 0; i < op.size(); i++){
        if (op[i] > 0) {
            op[i]--;
            bt(A, op, index + 1, get_val(A, index, i, value));
            op[i]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<int> op(4, 0);

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++){
        cin >> op[i];
    }

    // N개의 숫자 => N - 1개의 연산자 자리 => (N-1)! / 겹치는 숫자
    bt(A, op, 0, 0);

    cout << g_max << '\n' << g_min;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int N;
// vector<int> numbers;
// vector<int> operators(4); // +, -, *, /

// int maxValue = -1e9; // 초기값을 음의 무한대로 설정
// int minValue = 1e9;  // 초기값을 양의 무한대로 설정

// void calculate(int idx, int result) {
//     if (idx == N) {
//         maxValue = max(maxValue, result);
//         minValue = min(minValue, result);
//         return;
//     }

//     for (int i = 0; i < 4; ++i) {
//         if (operators[i] > 0) {
//             operators[i]--;
//             int nextResult = result;
//             if (i == 0) nextResult += numbers[idx];
//             else if (i == 1) nextResult -= numbers[idx];
//             else if (i == 2) nextResult *= numbers[idx];
//             else if (i == 3) nextResult /= numbers[idx];

//             calculate(idx + 1, nextResult);

//             operators[i]++;
//         }
//     }
// }

// int main() {
//     cin >> N;
//     numbers.resize(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> numbers[i];
//     }
//     for (int i = 0; i < 4; ++i) {
//         cin >> operators[i];
//     }

//     calculate(1, numbers[0]);

//     cout << maxValue << endl;
//     cout << minValue << endl;

//     return 0;
// }
