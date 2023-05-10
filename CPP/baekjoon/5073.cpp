#include <iostream>
using namespace std;

int main(){
    int a, b, c;

    cin >> a >> b >> c;
    while (a != 0 && b != 0 && c != 0)
    {
        if (a + b > c && b + c > a && c + a > b) {
            if (a == b && b == c) cout << "Equilateral" << endl;
            else if (a == b || b == c || a == c) cout << "Isosceles" << endl;
            else cout << "Scalene" << endl;
        }
        else cout << "Invalid" << endl;

        cin >> a >> b >> c;
    }
    return 0;
}