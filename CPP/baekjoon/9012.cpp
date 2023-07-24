#include <iostream>
#include <string>

class node
{
private:
    char c;
    node *next;
public:
    node(char c) : c(c), next(nullptr) { }
    ~node() { }
    node *get_next(){
        return next;
    }
    void set_next(node *next){
        this->next = next;
    }
    char get_val(){
        return c;
    }
};

class stack
{
private:
    node *head;
    int size;
    int answer;
public:
    stack() : head(nullptr), size(0), answer(0) { }
    ~stack(){
        while (head != nullptr)
        {
            if (answer < 0) answer -= 10000;
            node *tmp = head;
            if (head->get_val() == ')') answer++;
            else answer--;
            head = head->get_next();
            delete tmp;
        }
        if (answer == 0) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    void push(char c){
        node *insert = new node(c);
        insert->set_next(head);
        head = insert;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    std::string str;
    for (int i = 0; i < T; i++){
        stack S;
        std::cin >> str;
        for (int i = 0; i < str.length(); i++)
            S.push(str[i]);
    }
    return 0;
}

// #include <iostream>
// #include <stack>
// #include <string>

// std::string isVPS(const std::string& str) {
//     std::stack<char> stack;

//     for (char ch : str) {
//         if (ch == '(') {
//             stack.push(ch);
//         } else if (ch == ')') {
//             if (stack.empty()) {
//                 return "NO";
//             } else {
//                 stack.pop();
//             }
//         }
//     }

//     return stack.empty() ? "YES" : "NO";
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int T;
//     std::cin >> T;

//     while (T--) {
//         std::string str;
//         std::cin >> str;
//         std::cout << isVPS(str) << '\n';
//     }
//     return 0;
// }
