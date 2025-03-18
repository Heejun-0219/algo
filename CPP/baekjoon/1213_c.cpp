#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);

    std::string input;
    std::cin >> input;
    std::vector<int> arr(200, 0);

    for (char c : input) arr[c]++;
    std::string start, end;
    char mid;
    std::int64_t odd_flag = 0;

    for (int i = 'Z'; i >= 'A'; i--) {
        if (arr[i] & 1) {
            odd_flag++;
            mid = char(i);
        }
        for (int j = 0; j < arr[i] / 2; j++) {
            start = char(i) + start;
            end += char(i);
        }
    }
    if (mid) start += mid;
    if (odd_flag > 1) 
        std::cout << "I'm Sorry Hansoo\n";
    else 
        std::cout << start << end << std::endl;

    return 0;
}
