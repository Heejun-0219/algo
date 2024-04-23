#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka") i += 1;
        else if (i < s.size() - 2 && s.substr(i, 3) == "chu") i += 2;
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}
