#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

bool checkName(const std::string& name) {
    int length = name.length();
    
    if (length < 2 || length > 20)
        return false;

    bool firstCharCapital = (name[0] >= 'A' && name[0] <= 'Z');
    bool lastCharCapital = (name[length - 1] >= 'A' && name[length - 1] <= 'Z');

    if (firstCharCapital && lastCharCapital) {
        for (int i = 1; i < length - 1; i++) {
            if (name[i] >= 'A' && name[i] <= 'Z')
                return false;
        }
    } else if (firstCharCapital) {
        for (int i = 1; i < length; i++) {
            if (name[i] >= 'A' && name[i] <= 'Z')
                return false;
        }
    } else if (lastCharCapital) {
        for (int i = 0; i < length - 1; i++) {
            if (name[i] >= 'A' && name[i] <= 'Z')
                return false;
        }
    } else {
        return false;
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, M;
    std::cin >> N >> M;

    std::map<int, std::string> pokemon_dict;
    std::unordered_map<std::string, int> reverse_Dict;
    std::string tmp;
    
    for (int i = 0; i < N; i++) {
        std::cin >> tmp;
        // if (checkName(tmp))
            pokemon_dict.insert(std::pair<int, std::string>(i + 1, tmp));
            reverse_Dict.insert(std::pair<std::string, int>(tmp, i + 1));
    }

    for (int i = 0; i < M; i++) {
        std::cin >> tmp;
        bool isDigit = (tmp[0] >= '0' && tmp[0] <= '9');

        if (isDigit) {
            auto it = pokemon_dict.find(std::stoi(tmp));
            if (it != pokemon_dict.end())
                std::cout << it->second << '\n';
        } else {
            auto it = reverse_Dict.find(tmp);
            if (it != reverse_Dict.end())
                std::cout << it->second << '\n';
        }
    }

    return 0;
}

// #include <iostream>
// #include <unordered_map>
// #include <string>
// using namespace std;

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(0);
//     int N, M;
//     cin >> N >> M;

//     unordered_map<string, int> nameToNumber;
//     unordered_map<int, string> numberToName;

//     for (int i = 1; i <= N; i++) {
//         string name;
//         cin >> name;
//         nameToNumber[name] = i;
//         numberToName[i] = name;
//     }

//     for (int i = 0; i < M; i++) {
//         string query;
//         cin >> query;

//         if (isdigit(query[0])) {
//             int number = stoi(query);
//             cout << numberToName[number] << '\n';
//         } else {
//             cout << nameToNumber[query] << '\n';
//         }
//     }

//     return 0;
// }
