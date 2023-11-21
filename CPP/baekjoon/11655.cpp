#include <iostream>
#include <string>

using namespace std;

string ROT13(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            char base = islower(str[i]) ? 'a' : 'A';
            str[i] = (str[i] - base + 13) % 26 + base;
        }
    }
    return str;
}

int main() {
    string input;
    getline(cin, input);
    string result = ROT13(input);
    cout << result << endl;
    return 0;
}
