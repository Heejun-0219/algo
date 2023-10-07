#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// bool side_cal(vector<int> a, int index, int val){
//     int cnt = 0;
    
//     // for (int i = index; i >= 0; i--){
//     //     if (val > a[i]) {
//     //         cnt++;
//     //         break;
//     //     }
//     // }
//     if (*min_element(a.begin(), a.begin() + index + 1) != val) cnt++;
//     // cout << *min_element(a.begin(), a.begin() + index + 1) << " ";
    
//     // for (int i = index; i < a.size(); i++){
//     //     if (val > a[i]) {
//     //         cnt++;
//     //         break;
//     //     }
//     // }
//     if (*min_element(a.begin() + index, a.end()) != val) cnt++;
//     // cout << *min_element(a.begin() + index, a.end()) << endl;
//     return (cnt == 2 ? false : true);
// }

int solution(vector<int> a) {
    int answer = 0;
    
    if (a.size() < 3) return 0;
    
    vector<long long> m_left(a.size());
    long long min = 1000000001;
    for (int i = 0; i < a.size() ; i++){
        if (min > a[i]) {
            min = a[i];
        }
        m_left[i] = min;
    }
    
    min = 1000000001;
    vector<long long> m_right(a.size());
    for (int i = a.size() - 1; i >= 0; i--){
        if (min > a[i]) {
            min = a[i];
            
        }
        m_right[i] = min;
    }
    
    // for (long long it : m_left) cout << it << " " << endl;
    // for (long long it : m_right) cout << it << " " << endl;
    
    answer = 2;
    for (int i = 1; i < a.size() - 1; i++){
        if (m_left[i - 1] >= a[i] || a[i] <= m_right[i + 1]) answer++;
    }
    // for (int i = 1; i < a.size() - 1; i++){
    //     if (!(*min_element(a.begin(), a.begin() + i + 1) != a[i] && \
    //         *min_element(a.begin() + i, a.end()) != a[i])) answer++;
    // }
    
    return answer;
}
