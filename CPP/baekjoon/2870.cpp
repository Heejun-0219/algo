#include <bits/stdc++.h>

using namespace std;

vector<string> v;
string val;

void push() {
    while (true)
    {
        if (val.size() && val.front() == '0') val.erase(val.begin());
        else break;
    }
    if (val == "") val += "0";
    v.push_back(val);    
}

bool cmp(string a, string b) {
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        val = "";
        for (int j = 0; j < str.size(); j++) {
            if (str[j] >= '0' && str[j] <= '9') {
                val += str[j];
            }
            else {
                if (val != "") push();
                val = "";
            }
        }

        if (val != "")
            push();
    }

    sort(v.begin(), v.end(), cmp);

    for (const auto& it : v) {
        cout << it << '\n';
    }

    return 0;
}