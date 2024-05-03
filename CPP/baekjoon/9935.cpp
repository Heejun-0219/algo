#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    string target;
    cin >> target;
    
    string ret;
    for (char& c : s) {
        ret += c;
        if (ret.size() >= target.size() && ret.substr(ret.size() - target.size(), target.size()) == target) 
            ret.erase(ret.end() - target.size(), ret.end());
    }

    if (ret.size()) 
        cout << ret << endl;
    else
        cout << "FRULA\n";    

    return 0;
}
