#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n;

    cin >> n;

    int i;
    int sum;
    vector<int> v;
    do
    {
        v.push_back(1);
        for (i = 2; i <= sqrt(n); i++){
            if (n % i == 0){
                v.push_back(i);
                if (i != n / i) v.push_back(n / i);
            }
        }
        sort(v.begin(), v.end());
        sum = accumulate(v.begin(), v.end(), 0);
        if (sum == n){
            cout << sum << " = ";
            cout << v[0];
            for (i = 1; i < v.size(); i++){
                cout << " + " <<  v[i];
            }
            cout << endl;
        }
        else cout << n << " is NOT perfect." << endl;
        v.clear();
        cin >> n;
    } while (n != -1);
    

    return 0;
}