#include <iostream>
#include <string>
#include <vector>

class node
{
private:
    int val;
    node *next;
public:
    node(int val) : val(val), next(nullptr) { }
    ~node() { }
    node *get_next() { return next; }
    int get_val() { return val; }
    void set_next(node *next) { this->next = next; }
};

class stack
{
private:
    node *head;
    int size;
public:
    stack() : head(nullptr), size(0) { }
    ~stack() { 
        while(head != nullptr) {
            node *temp = head;
            head = head->get_next();
            delete temp;
        }
    }
    int get_val() {
        return size > 0 ? head->get_val() : -1;
    }
    int get_size() {
        return size;
    }
    void push(int val) {
        node *n = new node(val);
        n->set_next(head);
        head = n;
        size++;
    }
    int pop() {
        if (size == 0)
            return -1;
        int val = head->get_val();
        node *temp = head;
        head = head->get_next();
        delete temp;
        size--;
        return val;
    }
};

int main(){
    stack S;
    int N;
    std::cin >> N;
    std::string tmp;
    for (int i = 0; i <= N; i++){
        getline(std::cin, tmp);
        if (tmp.find("push") == 0){
            S.push(atoi(&tmp[tmp.find('h') + 2]));
        }
        else if (tmp.find("pop") == 0){
            std::cout << S.pop() << std::endl;
        }
        else if (tmp.find("size") == 0){
            std::cout << S.get_size() << std::endl;
        }
        else if (tmp.find("empty") == 0){
            std::cout << (S.get_size() == 0 ? 1 : 0) << std::endl;
        }
        else if (tmp.find("top") == 0){
            std::cout << S.get_val() << std::endl;
        }
    }
    return 0;
}

// #include <iostream>
// #include <string>
// #include <unordered_map>

// class node
// {
// private:
//     int val;
//     node *next;
// public:
//     node(int val) : val(val), next(nullptr) { }
//     ~node() { }
//     node *get_next() { return next; }
//     int get_val() { return val; }
//     void set_next(node *next) { this->next = next; }
// };

// class stack
// {
// private:
//     node *head;
//     int size;
// public:
//     stack() : head(nullptr), size(0) { }
//     ~stack() { 
//         while(head != nullptr) {
//             node *temp = head;
//             head = head->get_next();
//             delete temp;
//         }
//     }
//     int get_val() {
//         return size > 0 ? head->get_val() : -1;
//     }
//     int get_size() {
//         return size;
//     }
//     void push(int val) {
//         node *n = new node(val);
//         n->set_next(head);
//         head = n;
//         size++;
//     }
//     int pop() {
//         if (size == 0)
//             return -1;
//         int val = head->get_val();
//         node *temp = head;
//         head = head->get_next();
//         delete temp;
//         size--;
//         return val;
//     }
// };

// int main(){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
    
//     stack S;
//     int N;
//     std::cin >> N;
//     std::string cmd;
//     std::unordered_map<std::string, int> command_map = {{"push", 0}, {"pop", 1}, {"size", 2}, {"empty", 3}, {"top", 4}};
//     for (int i = 0; i < N; i++){
//         std::cin >> cmd;
//         switch (command_map[cmd]) {
//             case 0:
//                 int val;
//                 std::cin >> val;
//                 S.push(val);
//                 break;
//             case 1:
//                 std::cout << S.pop() << '\n';
//                 break;
//             case 2:
//                 std::cout << S.get_size() << '\n';
//                 break;
//             case 3:
//                 std::cout << (S.get_size() == 0 ? 1 : 0) << '\n';
//                 break;
//             case 4:
//                 std::cout << S.get_val() << '\n';
//                 break;
//         }
//     }
//     return 0;
// }
