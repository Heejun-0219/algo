#include <iostream>
using namespace std;

int main(){
    int n;
    int base = 1;
    int sum = 0;

    cin >> n;

    while (n > sum)
    {
        sum += base;
        base++;
    }
    base--;
    
    if (base % 2 == 0)
        cout << base - (sum - n) << "/" << sum - n + 1 << endl;
    else
        cout << sum - n + 1 << "/" << base - (sum - n) << endl;
    return 0;
}