#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::cin >> N;

    std::vector<long long> val(N);
    std::unordered_map<long long, int> freq;

    for (int i = 0; i < N; i++){
        std::cin >> val[i];
        freq[val[i]]++;
    }

    std::cin >> M;
    long long card;
    for (int i = 0; i < M; i++){
        std::cin >> card;
        std::cout << freq[card] << ' ';
    }

    return 0;
}

// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(0);

//     int N, M;
//     cin >> N;
    
//     unordered_map<int, int> cards;
    
//     for (int i = 0; i < N; i++) {
//         int num;
//         cin >> num;
//         cards[num]++;
//     }
    
//     cin >> M;
    
//     for (int i = 0; i < M; i++) {
//         int target;
//         cin >> target;
//         cout << cards[target] << " ";
//     }
    
//     return 0;
// }
