#include <iostream>
using namespace std;

int main(){
    string arr[5];
    string str;

    for (int i = 0; i < 5; i++){
        getline(cin, str);
        arr[i] = str;
    }

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 5; j++){
            if (i < arr[j].length())
                cout << arr[j][i];
            else
                continue;
        }
    }
    cout << endl;
    return 0;
}
