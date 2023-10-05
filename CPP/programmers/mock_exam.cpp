#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 5, 8, 10

// 1, 2, 3, 4, 5
// 2, 1, 2, 3, 2, 4, 2, 5 
// 3, 3, 1, 1, 2, 2, 4, 4, 5, 5

int fir_size = 5;
int sec_size = 8;
int thir_size = 10;

vector<int> first = {1, 2, 3, 4, 5};
vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> indexs(3, 0);
    vector<int> cnt(3, 0);
    for (int ans : answers){
        if (ans == first[indexs[0]++ % fir_size]) cnt[0]++;
        if (ans == second[indexs[1]++ % sec_size]) cnt[1]++;
        if (ans == third[indexs[2]++ % thir_size]) cnt[2]++;
    }
    
    int max = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < cnt.size(); i++){
        if (max == cnt[i])
            answer.push_back(i + 1);
    }
    
    return answer;
}
