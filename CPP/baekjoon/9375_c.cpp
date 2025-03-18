#include <iostream>
#include <map>
#include <string>
using namespace std;
int n, m;
void go(int cnt) {
    map<string, int> m;

    string name, category;
    while (cnt--)
    {
        cin >> name >> category;
        m[category]++;
    }
    
    long long ret = 1;
    for (const auto& i : m) {
        ret *= (i.second + 1);
    }
    cout << ret - 1 << '\n';
}
int main() {
    cin >> n;

    while (n--)
    {
        cin >> m;
        go(m);
    }    

    return 0;
}
