#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> selectionSort(const vector<int> &arr) {
    int N = arr.size();
    vector<int> P(N);
    vector<bool> used(N);

    for (int i = 0; i < N; i++) {
        int min_val = INT_MAX;
        int min_idx = -1;

        for (int j = 0; j < N; j++) {
            if (!used[j] && arr[j] < min_val) {
                min_val = arr[j];
                min_idx = j;
            }
        }

        P[min_idx] = i;
        used[min_idx] = true;
    }

    return P;
}

int main() {
    int N;
    cin >> N;

    srand(time(0));
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 1001;
        cout << A[i] << " ";
    }
    cout << endl << endl;

    vector<int> P = selectionSort(A);

    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    cout << endl;

    return 0;
}
