#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;

    vector<int> positions(N);
    for (int i = 0; i < N; i++) {
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    int gap = positions[1] - positions[0];
    for (int i = 2; i < N; i++) {
        gap = gcd(gap, positions[i] - positions[i - 1]);
    }

    int min_trees = 0;
    for (int i = 1; i < N; i++) {
        min_trees += (positions[i] - positions[i - 1]) / gap - 1;
    }

    cout << min_trees << endl;

    return 0;
}
