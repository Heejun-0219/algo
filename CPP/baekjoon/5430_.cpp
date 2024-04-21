#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int n;
deque<int> getVector() {
    deque<int> a;
    string s;
    cin >> s;

    string tmp;
    for (const char c : s) {
        if (isdigit(c)) {
            tmp += c;
        }
        else if (tmp.size()) {
            a.push_back(stoi(tmp));
            tmp.clear();
        }
    }

    return a;
}

void goPrint(deque<int>& dq, bool reverseFlag) {
        cout << '[';
        while (!dq.empty()) {
            if (reverseFlag) {
                cout << dq.back();
                dq.pop_back();
            } else {
                cout << dq.front();
                dq.pop_front();
            }
            
            if (!dq.empty()) {
                cout << ',';
            }
        }
        cout << "]\n";
}

void go() {
    string s;
    cin >> s;

    int size;
    cin >> size;

    deque<int> a = getVector();

    bool reverseFlag = false;
    for (char c : s) {
        if (c == 'R') {
            reverseFlag = !reverseFlag;
        }
        else if (c == 'D') {
            if (a.empty()) {
                cout << "error" << endl;
                return;
            }
            
            reverseFlag ? a.pop_back() : a.pop_front();
        }
    }

    goPrint(a, reverseFlag);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while (n--)
    {
        go();
    }

    return 0;
}
