#include <iostream>
using namespace std;

int main(){
    int x, y, w, h, a, b;

    cin >> x >> y >> w >> h;

    if (x  > w - x) a = w - x;
    else a = x;

    if (y > h - y) b = h - y;
    else b = y;

    cout << (a > b ? b : a) << endl;

    return 0;
}
