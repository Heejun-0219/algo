#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, pair<int, string> > a, pair<int, pair<int, string> > b) {
    if (a.second.first == b.second.first) {
        return a.first < b.first;
    } else {
        return a.second.first < b.second.first;
    }
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, pair<int, string> > > v(N);

    for (int i = 0; i < N; i++) {
        v[i].first = i;
        cin >> v[i].second.first >> v[i].second.second;
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << v[i].second.first << " " << v[i].second.second << "\n";
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool compare(pair<int, string> a, pair<int, string> b) {
//     return a.first < b.first;
// }

// int main() {
//     int N;
//     cin >> N;

//     vector<pair<int, string>> v(N);

//     for (int i = 0; i < N; i++) {
//         cin >> v[i].first >> v[i].second;
//     }

//     stable_sort(v.begin(), v.end(), compare);

//     for (int i = 0; i < N; i++) {
//         cout << v[i].first << " " << v[i].second << "\n";
//     }

//     return 0;
// }