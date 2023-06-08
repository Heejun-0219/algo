#include <iostream>
#include <set>
#include <algorithm>

int main(){
    int M, N;
    std::cin >> M >> N;

    std::set<int> A;
    int tmp;
    for (int i = 0; i < M; i++){
        std::cin >> tmp;
        A.insert(tmp);
    }

    std::set<int> B;
    for (int i = 0; i < N; i++){
        std::cin >> tmp;
        B.insert(tmp);
    }

    int count = 0;
    for (const auto& element : A){
        if (B.find(element) != B.end())
            count++;
    }
    std::cout << M + N - 2 * count;

    return 0;
}