#include <iostream>
#include <set>
#include <string>

int main(){
    int N;
    std::cin >> N;

    std::set<std::string> A;
    std::string tmp;
    int sum = 0;
    for (int i = 0; i < N; i++){
        std::cin >> tmp;
        if (tmp.compare("ENTER") == 0){
            sum += A.size();
            A.clear();
        }
        else {
            A.insert(tmp);
        }
    }
    sum += A.size();
    std::cout << sum;

    return 0;
}
