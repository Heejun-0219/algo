#include <iostream>
using namespace std;

int main(){
    int value;

    cin >> value;

    for (int i = 1; i <= value; i++){
        for (int j = 1; j <= value - i; j++){
            cout << " ";   
        }
        for (int j = 1; j <= 2 * i - 1; j++){
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i <= value - 1; i++){
        for (int j = 1; j <= i; j++){
            cout << " ";
        }
        for (int j = 1; j <= 2 * (value - i) - 1; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}