#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

inline bool isPrime(long long int val)
{
    if (val <= 1)
        return false;

    for (long long int i = 2; i <= val / i; i++)
    {
        if (val % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long step = n;

    int ret = 0;
    vector<long long> v;
    while (step)
    {
        if (!isPrime(step)) {
            step--; continue;
        }

        if (v.size()) {
            for (int i = 0; i < v.size(); i++) {
                if (v[i] > n) v.erase(v.begin() + i);
                if (v[i] == n) {
                    v.erase(v.begin() + i);
                    ret++;
                }
                v[i] += step;
            }
        }
        v.push_back(step--);
    }
    if (v.size()) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > n) v.erase(v.begin() + i);
            if (v[i] == n) {
                v.erase(v.begin() + i);
                ret++;
            }
            v[i] += step;
        }
    }
    cout << ret << endl;

    return 0;
}