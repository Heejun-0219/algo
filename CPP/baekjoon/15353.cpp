#include <iostream> 
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int aSize = a.size() - 1;
    int bSize = b.size() - 1;

    string value = "";
    int over = 0;
    while (true)
    {
        if (aSize < 0 && bSize < 0) break;

        int aValue = 0, bValue = 0;
        if (aSize >= 0) {
            aValue = a[aSize--] - '0';
        }

        if (bSize >= 0) {
            bValue = b[bSize--] - '0';
        }

        int unitSum = over + aValue + bValue;
        over = unitSum / 10;

        value = to_string(unitSum % 10) + value;
    }

    if (over) value = to_string(over) + value;
    cout << value << endl;    

    return 0;
}
