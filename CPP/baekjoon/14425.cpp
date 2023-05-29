#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

int main(){
    int N, M;
    std::cin >> N >> M;

    std::set<std::string> my_set;
    std::string tmp;
    for (int i = 0; i < N; i++){
        std::cin >> tmp;
        my_set.insert(tmp);
    }

    std::vector<std::string> query;
    for (int i = 0; i < M; i++){
        std::cin >> tmp;
        query.push_back(tmp);
    }

    int answer = 0;
    for (int i = 0; i < M; i++){
        if (my_set.find(query[i]) != my_set.end()){
            answer++;
        }
    }

    std::cout << answer << std::endl;
    return 0;
}


// #include <iostream>
// #include <unordered_set>
// #include <string>

// using namespace std;

// int main() {
// int N, M;
// cin >> N >> M;
// unordered_set<string> S;
// for (int i = 0; i < N; i++) {
//     string str;
//     cin >> str;
//     S.insert(str);
// }

// int count = 0;
// for (int i = 0; i < M; i++) {
//     string str;
//     cin >> str;
//     if (S.count(str) > 0) {
//         count++;
//     }
// }

// cout << count << endl;

// return 0;
// }