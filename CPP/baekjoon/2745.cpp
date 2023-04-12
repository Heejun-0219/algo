#include <iostream>
#include <string>
using namespace std;

int main() {
    string N;
    int B;
    int sum = 0;

    // 'A' 아아스키 코드 값은 65
    // 'Z' 아아스키 코드 값은 90
    cin >> N >> B;
    for (int i = 0; i < N.length(); i++){
        if (N[i] <= '9' && N[i] >= '0') {
            sum = sum * B + (N[i] - '0');
        } else if (N[i] <= 'Z' && N[i] >= 'A') {
            sum = sum * B + (N[i] - 'A' + 10);
        }
    }
    cout << sum << endl;
    return 0;
}