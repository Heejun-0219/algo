#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    // vector<vector<int>> Map(n, vector<int>(n));
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         Map[i][j] = (i > j ? i : j) + 1;
    //         cout << i << " " << j << " " << Map[i][j] << '\n';
    //     }
    // }
    
    // vector<int> arr;
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         arr.push_back((i > j ? i : j) + 1);
    //     }
    // }
    
//     for (int i = left / n; i <= right / n; i++){
//         int start = 0;
//         int end = n - 1;
        
//         if (i == left / n) {
//             start = left % n;
//         }
//         else if (i == right / n){
//             end = right % n;
//         }
        
//         for (int j = start; j <= end; j++){
//             answer.push_back((i > j ? i : j) + 1);
//         }
//     }
    
    int div, rest;
    for (long long i = left; i <= right; i++) {
        div = i / n;
        rest = i % n;
        
        if (div > rest)
            rest = div;
        
        answer.push_back(rest + 1);
    }
    
    return answer;
}
