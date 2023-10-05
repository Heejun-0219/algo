#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int x, y;
    for (int i = 0; i < park.size(); i++){
        if ((y = park[i].find('S')) != string::npos) {
            x = i;
            break;
        }
    }
    // answer.push_back(x);
    // answer.push_back(y);
    
    
    int x_map = park.size() - 1;
    int y_map = park[0].size() - 1;
    for (string route : routes) {        
        int dis = stoi(route.substr(2));
        int flag = 0;
        char direction = route[0];
        switch(direction){
            case 'N':
                if (x - dis < 0)
                    continue;
                
                for (int i = x; i >= x - dis; i--){
                    if (park[i][y] == 'X')
                        flag = 1;
                    }
                if (flag) continue;
                
                x -= dis;
                
                break;
            case 'S':
                if (x + dis > x_map)
                    continue;
                
                for (int i = x; i <= x + dis; i++){
                    if (park[i][y] == 'X')
                        flag = 1;
                    }
                if (flag) continue;
                
                x += dis;
                
                break;
            case 'W':
                if (y - dis < 0)
                    continue;
                
                for (int i = y; i >= y - dis; i--){
                    if (park[x][i] == 'X')
                        flag = 1;
                    }
                if (flag) continue;
                
                y -= dis;
                
                break;
            case 'E':
                if (y + dis > y_map)
                    continue;
                
                for (int i = y; i <= y + dis; i++){
                    if (park[x][i] == 'X')
                        flag = 1;
                    }
                if (flag) continue;
                
                y += dis;
                
                break;
            default:
                break;
        }
    }
 
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}
