#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Element
{
    int index;
    int value;
};

bool campore(const Element &a, const Element &b){
    if (a.value == b.value){
        return a.index < b.index;
    }
    return a.value < b.value;
}

int main(){
    int N;
    cin >> N;

    vector<long long> arr(N);
    vector<Element> sortedA(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sortedA[i].index = i;
        sortedA[i].value = arr[i];
    }
    // sort
    sort(sortedA.begin(), sortedA.end(), campore);

    vector<int> P(N);
    for (int i = 0, j = 0; i < N; i++, j++){
        P[sortedA[i].index] = j;
        while (i != N && sortedA[i].value == sortedA[i+1].value){
            P[sortedA[i+1].index] = P[sortedA[i].index];
            i++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <map>

// using namespace std;

// int main() {
//     int N;
//     cin >> N;

//     vector<int> coordinates(N);
//     for (int i = 0; i < N; i++) {
//         cin >> coordinates[i];
//     }

//     vector<int> sortedCoordinates = coordinates;
//     sort(sortedCoordinates.begin(), sortedCoordinates.end()); // 좌표를 정렬합니다.

//     map<int, int> compressedCoordinates; // 압축된 좌표를 저장할 맵입니다.

//     int idx = 0;
//     for (int i = 0; i < N; i++) {
//         if (compressedCoordinates.find(sortedCoordinates[i]) == compressedCoordinates.end()) {
//             compressedCoordinates[sortedCoordinates[i]] = idx++;
//         }
//     }

//     for (int i = 0; i < N; i++) {
//         cout << compressedCoordinates[coordinates[i]] << " ";
//     }
//     cout << endl;

//     return 0;
// }
