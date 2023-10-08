#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;

bool str_index_compare(string front, string back){
    // cout << front[N] << " " << back[N] << " " << (front[N] < back[N]) << '\n';
    if (front[N] == back[N])
        return front < back;
    return front[N] < back[N];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    N = n;
    
    // sort(answer.begin(), answer.end());
    sort(answer.begin(), answer.end(), str_index_compare); 
    
    return answer;
}
