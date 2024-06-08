#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> getSubarraySums(const vector<int>& pizza, int size) {
    vector<int> subarraySums;

    for (int i = 0; i < size; ++i) {
        int sum = 0;
        for (int j = 0; j < size - 1; ++j) {
            sum += pizza[(i + j) % size];
            subarraySums.push_back(sum);
        }
    }
    
    subarraySums.push_back(accumulate(pizza.begin(), pizza.end(), 0));
    return subarraySums;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, m, n;
    cin >> k >> m >> n;

    vector<int> pizzaA(m);
    vector<int> pizzaB(n);

    for (int i = 0; i < m; ++i) {
        cin >> pizzaA[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> pizzaB[i];
    }

    vector<int> subA = getSubarraySums(pizzaA, m);
    vector<int> subB = getSubarraySums(pizzaB, n);

    sort(subA.begin(), subA.end());
    sort(subB.begin(), subB.end());

    int count = 0;

    for (int a : subA) {
        if (a == k) count++;
        if (a < k) {
            count += upper_bound(subB.begin(), subB.end(), k - a) - lower_bound(subB.begin(), subB.end(), k - a);
        }
    }

    count += count_if(subB.begin(), subB.end(), [k](int b){ return b == k; });

    cout << count << '\n';

    return 0;
}
