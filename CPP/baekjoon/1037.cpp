#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N;
    std::cin >> N;

    std::vector<int> A;
    int tmp;
    for (int i = 0; i < N; i++){
        std::cin >> tmp;
        if (tmp != 1)
            A.push_back(tmp);
    }

    if (N >= 2){
        std::sort(A.begin(), A.end());
        std::cout << A[0] * A[N - 1];
    }
    else 
        std::cout << A[0] * A[0];

    return 0;
}
