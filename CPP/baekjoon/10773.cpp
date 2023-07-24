#include <iostream>

class node
{
private:
    long long val;
    node *next;
public:
    node(long long val) : val(val), next(nullptr) {} 
    ~node() { }
    node *get_next() { return next; }
    long long get_val() { return val; }
    void set_next(node *n) { this->next = n; }
};

class stack
{
private:
    node *head;
    int sum;
public:
    stack() : head(nullptr), sum(0) { }
    ~stack() {
        while (head != nullptr)
        {
            node *tmp = head;
            head = head->get_next();
            sum += tmp->get_val();
            delete tmp;
        }
        std::cout << sum;
    }
    void push(long long val){
        node *insert = new node(val);
        insert->set_next(head);
        head = insert;
    }
    void pop(){
        node *remove = head;
        head = head->get_next();
        delete remove;
    }
};

int main(){
    stack S;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int K;
    std::cin >> K;

    long long val;
    for (int i = 0; i < K; i++){
        std::cin >> val;
        if (val == 0){
            S.pop();
        }
        else {
            S.push(val);
        }
    }
    return 0;
}
