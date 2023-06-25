#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

struct CompareLengthAndLexical {
    bool operator()(const std::string& str1, const std::string& str2) const {
        if (str1.length() != str2.length()) {
            return str1.length() > str2.length();
        }
        return str1 < str2;
    }
};


int main(){
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A;
    std::string tmp;
    for (int i = 0; i < N; i++){
        std::cin >> tmp;
        if (tmp.length() >= M)
            A.push_back(tmp);
    }

    std::map<std::string, int> m;
    for (std::string s : A){
        m[s]++;
    }

    int max_fre = 0;

    for (const auto& p : m){
        if (p.second > max_fre){
            max_fre = p.second;
        }
    }

    std::vector<std::string> answer;
    for (int i = max_fre; i > 0; i--){
        std::set<std::string, CompareLengthAndLexical> t;
        for (const auto& p : m){
            if (i == p.second){
                t.insert(p.first);
                // answer.push_back(p.first);
            }
        }
        answer.insert(answer.end(), t.begin(), t.end());
    }

    for (const auto& p : answer){
        std::cout << p << "\n";
    }
    return 0;
}