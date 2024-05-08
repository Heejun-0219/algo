#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    string target;
    cin >> target;

    stack<char> st;
    for (char c : s) {
        st.push(c);
        if (st.size() >= target.size() && st.top() == target[target.size() - 1]) {
            string tmp = "";
            for (int i = 0; i < target.size(); i++) {
                tmp += st.top();
                st.pop();
            }
            reverse(tmp.begin(), tmp.end());
            if (tmp != target) {
                for (char ch : tmp) st.push(ch);
            }
        }
    }

    if (st.size()) {
        string tmp = "";
        while(st.size()) {
            tmp += st.top();
            st.pop();
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << endl;
    }
    else {
        cout << "FRULA\n";
    }

    return 0;
}
