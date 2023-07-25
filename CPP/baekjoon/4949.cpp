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
    char get_val(){
        return c;
    }
    void set_next(node *next){
        this->next = next;
    }
};

class stack
{
private:
    node *head;
    int size;
    int size_s;
    int size_l;
    bool flag;
public:
    stack() : head(nullptr), size(0), size_s(0), size_l(0), flag(true) { }
    ~stack(){

    }
    void push(char c){
        node *tmp = new node(c);
        tmp->set_next(head);
        head = tmp;
        size++;
        if (c == '(') size_s++;
        else size_l++;
    }
    char pop(char ch){
        if (size > 0){
            node *tmp;
            char c = head->get_val();
            tmp = head;
            head = head->get_next();
            delete tmp;
            size--;
            if (ch == ')') {
                size_s--;
                if (c == '[')
                    return '*';
            }
            else 
            {
                size_l--;
                if (c == '(')
                    return '*';
            }
            return c;
        }
        return '*';
    }
    void set_flag(){
        flag = !flag;
    }
    std::string get_answer(){
        if (size_s != 0 || size_l != 0)
            flag = false;
        return (flag ? "yes" : "no");
    }
};

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str;
    getline(std::cin, str);
    while (!(str.length() == 1 && str[0] == '.'))
    {
        stack S;
        for (int i = 0; i < str.length(); i++){
            if ((str[i] >= 'a' && str[i] <= 'z') || \
                (str[i] >= 'A' && str[i] <= 'Z') || \
                str[i] == ' ' || str[i] == '.'){
                    continue;
                }
            else if (str[i] == '(' || str[i] == '[' ){
                    S.push(str[i]);    
                }
            else if (str[i] == ')' || str[i] == ']'){
                if (S.pop(str[i]) == '*')
                {
                    S.set_flag();
                    break;
                }
            }
            else{
                S.set_flag();
                break;
            }
        }
        std::cout << S.get_answer() << std::endl;
        getline(std::cin, str);
    }
    return 0;
}

// #include <iostream>
// #include <stack>
// #include <string>

// bool isBalanced(const std::string &str) {
//     std::stack<char> stack;

//     for (char ch : str) {
//         switch (ch) {
//             case '(':
//             case '[':
//                 stack.push(ch);
//                 break;
//             case ')':
//                 if (stack.empty() || stack.top() != '(')
//                     return false;
//                 stack.pop();
//                 break;
//             case ']':
//                 if (stack.empty() || stack.top() != '[')
//                     return false;
//                 stack.pop();
//                 break;
//         }
//     }

//     return stack.empty();
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     std::string str;
//     while (std::getline(std::cin, str), str != ".") {
//         std::cout << (isBalanced(str) ? "yes" : "no") << '\n';
//     }

//     return 0;
// }