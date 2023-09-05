#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g_min = 1e9;
vector<int> A_TEAM;
vector<int> B_TEAM;

int cal_team(vector<vector<int> > map, char c) {
    int sum = 0;
    vector<int>* target;
    if (c == 'A')
        target = &A_TEAM;
    else 
        target = &B_TEAM;
    
    for (size_t i = 0; i < target->size(); ++i) {
        for (size_t j = i + 1; j < target->size(); ++j) {
            int first = (*target)[i];
            int second = (*target)[j];

            sum += map[first][second] + map[second][first];
        }
    }

    return sum;
}

void cal_min(vector<vector<int> > map, int N) {
    int index = 0;
    for (int i = 0; i < N; i++) {
        if (find(A_TEAM.begin(), A_TEAM.end(), i) == A_TEAM.end() && index < N / 2) {
            B_TEAM[index++] = i;
        }
    }

    int A = cal_team(map, 'A');
    int B = cal_team(map, 'B');

    if (abs(A - B) < g_min) g_min = abs(A - B);
}

void bt(vector<vector<int> > map, int N, int count, int index){
    if (count == N / 2){
        cal_min(map, N);
        return ;
    }

    for (int i = index; i < N; i++){
        A_TEAM[count] = i;
        bt(map, N, count + 1, i + 1);
        A_TEAM[count] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    A_TEAM.resize(N/2);
    B_TEAM.resize(N/2);
    vector<vector<int> > map(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    bt(map, N, 0, 0);

    cout << g_min;
    // for (const auto &row : map) {
    //     for (int val : row) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <algorithm>

// using namespace std;

// int main() {
//     int N;
//     cin >> N;
    
//     vector<vector<int>> S(N, vector<int>(N));
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < N; ++j) {
//             cin >> S[i][j];
//         }
//     }
    
//     int minDiff = 1e9; // 초기 최솟값 설정
    
//     for (int bitmask = 0; bitmask < (1 << N); ++bitmask) {
//         // 비트마스크를 통해 팀 분배 경우의 수를 표현
//         if (__builtin_popcount(bitmask) == N / 2) {
//             // 팀 분배가 조건을 만족하는 경우
//             vector<int> start, link;
//             for (int i = 0; i < N; ++i) {
//                 if (bitmask & (1 << i)) {
//                     start.push_back(i);
//                 } else {
//                     link.push_back(i);
//                 }
//             }
            
//             int startSum = 0, linkSum = 0;
//             for (int i = 0; i < N / 2; ++i) {
//                 for (int j = i + 1; j < N / 2; ++j) {
//                     startSum += S[start[i]][start[j]] + S[start[j]][start[i]];
//                     linkSum += S[link[i]][link[j]] + S[link[j]][link[i]];
//                 }
//             }
            
//             minDiff = min(minDiff, abs(startSum - linkSum));
//         }
//     }
    
//     cout << minDiff << endl;
    
//     return 0;
// }
