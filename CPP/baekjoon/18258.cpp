// #include <iostream>
// #include <string>

// class node
// {
// private:
//     int val;
//     node *next;
// public:
//     node(int val) : val(val), next(nullptr) { }
//     ~node() { }
//     int get_val() { return val; }
//     node *get_next() { return next; }
//     void set_next(node *next) { this->next = next; }
// };

// class queue
// {
// private:
//     node *head;
//     node *tail;
//     int size;
// public:
//     queue() : head(nullptr), tail(nullptr), size(0) { }
//     ~queue(){
//         node *del;
//         while (head != nullptr)
//         {
//             del = head;
//             head = head->get_next();
//             delete del;
//         }
//     }
//     void push(int val){
//         node *tmp = new node(val);
//         if (size == 0){
//             head = tmp;
//             tail = tmp;
//         }
//         else {
//             tail->set_next(tmp);
//             tail = tmp;
//         }
//         size++;
//     }
//     int pop(){
//         if (size > 0){
//             node *del = head;
//             int val = head->get_val();
//             head = head->get_next();
//             delete del;
//             size--;
//             return val;
//         }
//         return -1;
//     }
//     int get_size() { return size; }
//     int empty() { return (size > 0 ? 0 : 1); }
//     int front() { 
//         if (size > 0) 
//             return head->get_val();
//         return 1;
//     }
//     int back() { 
//         if (size > 0) 
//             return tail->get_val(); 
//         return 1;
//     }
// };

// int main(){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     queue Q;
//     int N;
//     std::cin >> N;

//     std::string str;
//     while (N--)
//     {
//         std::cin >> str;

//         if (str.find("push") == 0){
//             int val;
//             std::cin >> val;
//             Q.push(val);
//         }
//         else if (str.find("pop") == 0){
//             std::cout << Q.pop() << std::endl;
//         }
//         else if (str.find("size") == 0){
//             std::cout << Q.get_size() << std::endl;
//         }
//         else if (str.find("empty") == 0){
//             std::cout << Q.empty() << std::endl;
//         }
//         else if (str.find("front") == 0){
//             std::cout << Q.front() << std::endl;
//         }
//         else if (str.find("back") == 0){
//             std::cout << Q.back() << std::endl;
//         }
//         else {
//             N++;
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> Q;
    int N;
    cin >> N;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int val;
            cin >> val;
            Q.push(val);
        } 
        else if (cmd == "pop") {
            if (!Q.empty()){
                cout << Q.front() << '\n';
                Q.pop();
            }
            else 
                cout << -1 << '\n';
        }
        else if (cmd == "size") {
            cout << Q.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << (Q.empty() ? 1 : 0) << '\n';
        }
        else if (cmd == "front") {
            if (!Q.empty())
                cout << Q.front() << '\n';
            else
                cout << -1 << '\n';
        }
        else if (cmd == "back") {
            if (!Q.empty())
                cout << Q.back() << '\n';
            else
                cout << -1 << '\n';
        }
    }
    
    return 0;
}
