#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int rotate = s.length();
    
    while(rotate--){
        stack<int> St;
        int flag = 0;
        
        for (int index = 0; index < s.length(); index++){
            if (s[index] == '(' || s[index] == '[' || s[index] == '{')
                St.push(s[index]);
            else if (St.empty()){
                flag = 1;
                break;
            }
            else if (s[index] == ')'){
                if (St.top() != '(') {
                    flag = 1;
                    break;
                }
                St.pop();
            }
            else if (s[index] == ']'){
                if (St.top() != '[') {
                    flag = 1;
                    break;
                }
                St.pop();
            }
            else if (s[index] == '}'){
                if (St.top() != '{') {
                    flag = 1;
                    break;
                }
                St.pop();
            }
        }
        
        if (!flag && St.empty()) answer++;
        
        s = s.substr(1, s.length() - 1) + s[0];
    }
    
    return answer;
}

