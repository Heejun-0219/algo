#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Quick sort
struct Element {
    int index;
    int value;
};

bool compareValues(const Element &a, const Element &b) {
    if (a.value == b.value) {
        return a.index < b.index;
    }
    return a.value < b.value;
}

void quicksort(vector<Element> &arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = left + (right - left) / 2;
    Element pivot = arr[pivotIndex];

    int i = left, j = right;
    while (i <= j) {
        while (compareValues(arr[i], pivot)) {
            i++;
        }
        while (compareValues(pivot, arr[j])) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quicksort(arr, left, j);
    quicksort(arr, i, right);
}

int main() {
    int N;
    cin >> N;

    srand(time(0));
    vector<int> A(N);
    vector<Element> sortedA(N);

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 1001;
        cout << A[i] << " ";
        sortedA[i].index = i;
        sortedA[i].value = A[i];
    }
    cout << endl << endl;

    quicksort(sortedA, 0, N - 1);

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        P[sortedA[i].index] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    cout << endl;

    return 0;
}