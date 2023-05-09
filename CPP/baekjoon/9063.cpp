#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n, x_min, x_max, y_min, y_max, wide, x, y;

    cin >> n;

    wide = 0;
    x_min = y_min = INT_MAX;
    x_max = y_max = INT_MIN;
    while (n--)
    {
        cin >> x >> y;

        if (x < x_min) x_min = x;
        if (x > x_max) x_max = x;
        if (y < y_min) y_min = y;
        if (y > y_max) y_max = y;
    }
    wide = (x_max - x_min) * (y_max - y_min);
    cout << wide << endl;
    return 0;
}