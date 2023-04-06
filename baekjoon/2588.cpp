#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int move;
    int stand;

    int value = 0;

    cin >> move;
    cin >> stand;

    for (int i = 0; i < 3; i++){
        int tmp = move * (stand % 10);
        stand /= 10;
        cout << tmp << endl;
        value += tmp * (int)pow(10, i);
    }
    cout << value << endl;
    return 0;
}