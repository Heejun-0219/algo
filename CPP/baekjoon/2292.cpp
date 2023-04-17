#include <iostream>
using namespace std;

int main(){
    int n;
    int step = 1;
    int i = 1;

    cin >> n;
    while (step < n) step += 6 * i++;
    
    cout << i << endl;
    return 0;
}