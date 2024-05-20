#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n, fir, sec, ret, val, num;
vector<long long> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        long long tmp; 
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> num;
    sort(v.begin(), v.end());

    fir = 0, sec = v.size() - 1;
    val = v[fir] + v[sec];
    while (fir < sec)
    {
        if (val == num) ret++;
        if (val < num) {
            val -= v[fir++];
            val += v[fir];
        }
        else {
            val -= v[sec--];
            val += v[sec];
        }
    }
    cout << ret << endl;
    
    return 0;
}
