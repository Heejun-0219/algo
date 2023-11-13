#include <iostream>
#include <string>

using namespace std;

int countingStar[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    string input;
    cin >> input;

    for (char c : input) {
        countingStar[c - 97]++;
    }

    for (int val : countingStar) {
        cout << val << " ";
    }

    return 0;
}