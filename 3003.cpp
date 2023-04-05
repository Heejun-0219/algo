#include <iostream>
using namespace std;

#define SIZE 6

int main(){
    int base[SIZE] = {1, 1, 2, 2, 2, 8};
    int input[SIZE];

    for (int i = 0; i < SIZE; i++){
        cin >> input[i];
        cout << base[i] - input[i] << " ";
    }
    cout << endl;
    return 0;
}