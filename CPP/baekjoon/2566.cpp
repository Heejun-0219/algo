#include <iostream>
#define MAX 9
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[MAX][MAX];
    int x, y, num;

    for (int i = 0; i < MAX * MAX; i++){
        cin >> arr[i / MAX][i % MAX];
    }

    num = arr[0][0];
    for (int i = 0; i < MAX * MAX; i++){
        if (num < arr[i / MAX][i % MAX]){
            num = arr[i / MAX][i % MAX];
            x = i / MAX + 1;
            y = i % MAX + 1;
        }
    }
    cout << num << endl << x << " " << y;
    return 0;
}