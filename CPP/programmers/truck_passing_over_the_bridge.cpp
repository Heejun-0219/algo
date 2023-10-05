#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    if (*max_element(truck_weights.begin(), truck_weights.end()) > weight) 
        return 0;
    
    int current = 0;
    int index = 0;
    vector<pair<int, int>> bridge;
    while(true) {
        for (auto &time : bridge){
            if (time.second == answer){
                current -= time.first;
                bridge.erase(bridge.begin());
            }
        }
        
        for (int i = index; i < truck_weights.size() && current + truck_weights[i] <= weight; i++){
            bridge.push_back({truck_weights[i], answer + bridge_length});
            current += truck_weights[i];
            index++;
            break;
            // cout << bridge[i].first << " " << bridge[i].second << '\n';
        }
        
        answer++;
        if (bridge.empty()) break;
    }
    
    return answer;
}
