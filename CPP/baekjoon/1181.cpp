#include <iostream>
#include <string.h>
using namespace std;

// partition_im
int partition_im(int left, int right, string **arr) {
    int pivot = left;
    int low = left + 1;
    int high = right;

    while (low <= high) {
        while (low <= right && ((*arr)[low].length() < (*arr)[pivot].length() ||
                               ((*arr)[low].length() == (*arr)[pivot].length() && (*arr)[low] < (*arr)[pivot]))) {
            low++;
        }
        while (high >= (left + 1) && ((*arr)[high].length() > (*arr)[pivot].length() ||
                                      ((*arr)[high].length() == (*arr)[pivot].length() && (*arr)[high] > (*arr)[pivot]))) {
            high--;
        }
        if (low <= high) {
            string temp = (*arr)[low];
            (*arr)[low] = (*arr)[high];
            (*arr)[high] = temp;
            low++;
            high--;
        }
    }
    string temp = (*arr)[pivot];
    (*arr)[pivot] = (*arr)[high];
    (*arr)[high] = temp;
    return high;
}


// quicksort
void quicksort(int left, int right, string **arr) {
    if (left < right) {
        int pivot = partition_im(left, right, arr);
        quicksort(left, pivot - 1, arr);
        quicksort(pivot + 1, right, arr);
    }
}

// remove duplicates
int removeDuplicates(string **arr, int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int index = 0;

    for (int i = 0; i < n - 1; i++) {
        if ((*arr)[i] != (*arr)[i + 1]) {
            (*arr)[index++] = (*arr)[i];
        }
    }

    (*arr)[index++] = (*arr)[n - 1];

    return index;
}

int main() {
    int N;
    cin >> N;

    string *dic = new string[N];

    for (int i = 0; i < N; i++) {
        cin >> dic[i];
    }

    quicksort(0, N - 1, &dic);

    int newN = removeDuplicates(&dic, N);

    for (int i = 0; i < newN; i++) {
        cout << dic[i] << endl;
    }

    delete[] dic;

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <set>
// using namespace std;

// bool compare(string a, string b) {
//     if (a.length() == b.length())
//         return a < b;
//     else
//         return a.length() < b.length();
// }

// int main() {
//     int N;
//     cin >> N;
//     vector<string> words;
//     set<string> uniqueWords;

//     for (int i = 0; i < N; i++) {
//         string word;
//         cin >> word;
//         uniqueWords.insert(word);
//     }

//     for (const auto& word : uniqueWords) {
//         words.push_back(word);
//     }

//     sort(words.begin(), words.end(), compare);

//     for (const auto& word : words) {
//         cout << word << '\n';
//     }

//     return 0;
// }
