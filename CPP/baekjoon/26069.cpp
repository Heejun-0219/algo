#include <iostream>
#include <string>
#include <set>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::set<std::string> A;
    std::string front, back;
    int sum = 0;
    for (int i = 0; i < N; i++){
        std::cin >> front;
        std::cin >> back;

        if (front.compare("ChongChong") == 0 || back.compare("ChongChong") == 0){
            A.insert(front);
            A.insert(back);
        }

        if (A.find(front) != A.end() || A.find(back) != A.end()){
            A.insert(front);
            A.insert(back); 
        }
    }
    sum += A.size();
    std::cout << sum;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <set>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int N;
//     cin >> N;

//     vector<pair<string, string>> records(N);
//     for (int i = 0; i < N; i++) {
//         cin >> records[i].first >> records[i].second;
//     }

//     set<string> dancers;
//     dancers.insert("ChongChong");

//     for (auto& record : records) {
//         if (dancers.count(record.first)) {
//             dancers.insert(record.second);
//         } else if (dancers.count(record.second)) {
//             dancers.insert(record.first);
//         }
//     }

//     cout << dancers.size(); // ChongChong 제외한 인원 수 출력

//     return 0;
// }
