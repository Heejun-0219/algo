#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
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
    std::vector<std::string> nope;
    for (int i = 0; i < M; i++){
        if (my_set.find(query[i]) != my_set.end()){
            answer++;
            nope.push_back(query[i]);
        }
    }

    std::cout << answer << std::endl;
    sort(nope.begin(), nope.end());
    for (auto name : nope){
        std::cout << name << '\n';
    }
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <set>
// #include <string>
// #include <vector>

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(0);

//     int N, M;
//     std::cin >> N >> M;

//     std::set<std::string> unheard;
//     std::string name;

//     for (int i = 0; i < N; i++) {
//         std::cin >> name;
//         unheard.insert(name);
//     }

//     std::vector<std::string> unseen;
//     for (int i = 0; i < M; i++) {
//         std::cin >> name;
//         if (unheard.find(name) != unheard.end()) {
//             unseen.push_back(name);
//         }
//     }

//     std::sort(unseen.begin(), unseen.end());

//     std::cout << unseen.size() << '\n';
//     for (const auto& person : unseen) {
//         std::cout << person << '\n';
//     }

//     return 0;
// }
