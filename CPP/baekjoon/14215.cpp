#include <iostream>
using namespace std;

int main(){
    int x[3];

    int max = -1;
    int sum = 0;
    for (int i = 0; i < 3; i++){
        cin >> x[i];
        if (max < x[i]) max = x[i];
        sum += x[i];
    }

    if (x[0] + x[1] > x[2] && x[1] + x[2] > x[0] && x[2] + x[0] > x[1]){
        cout << sum << endl;
    }
    else{
        sum -= max;
        cout << sum + (sum - 1) << endl;
    }

    return 0;
}