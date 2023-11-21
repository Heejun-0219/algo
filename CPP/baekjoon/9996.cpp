#include <iostream>
#include <string>

using namespace std;

bool matchPattern(const string& pattern, const string& filename) {
    int p = 0, f = 0;

    while (p < pattern.length() && f < filename.length()) {
        if (pattern[p] == '*') {
            while (f < filename.length()) {
                if (matchPattern(pattern.substr(p + 1), filename.substr(f))) {
                    return true;
                }
                f++;
            }
        } else if (pattern[p] == filename[f] || pattern[p] == '?') {
            p++;
            f++;
        } else {
            return false;
        }
    }

    return (p == pattern.length() && f == filename.length());
}

int main() {
    int N;
    cin >> N;
    string pattern;
    cin >> pattern;

    for (int i = 0; i < N; i++) {
        string filename;
        cin >> filename;
        if (matchPattern(pattern, filename)) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }

    return 0;
}
