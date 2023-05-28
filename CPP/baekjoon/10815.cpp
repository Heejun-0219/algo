#include <iostream>
#include <set>
#include <vector>

int main() {
    int N, M;
    std::cin >> N;

    std::set<int> cards;
    for (int i = 0; i < N; ++i) {
        int card;
        std::cin >> card;
        cards.insert(card);
    }

    std::cin >> M;
    std::vector<int> query(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> query[i];
    }

    for (int i = 0; i < M; ++i) {
        if (cards.find(query[i]) != cards.end()) {
            std::cout << "1 ";
        } else {
            std::cout << "0 ";
        }
    }

    return 0;
}
