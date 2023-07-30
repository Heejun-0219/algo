#include <iostream>
#include <string>

using namespace std;

class node
{
private:
    int value;
    node *next;
    node *pre;
public:
    node(int value) : value(value), next(nullptr), pre(nullptr) { }
    ~node() { }
    int get_val(){ return value; }
    node *get_next() { return next; }
    node *get_pre() { return pre; }
    void set_next(node *next) { this->next = next; }
    void set_pre(node *pre) { this->pre = pre; }
};

class deque
{
private:
    node *head;
    node *tail;
    int size;
public:
    deque() : head(nullptr), tail(nullptr), size(0) { }
    ~deque() {
        node *tmp;
        while (head != nullptr)
        {
            tmp = head;
            head = head->get_next();
            delete tmp;
        }
    }
    void push_front(int val) {
        node *tmp = new node(val);
        if (size == 0){
            head = tmp;
            tail = tmp;
        }
        else {
            tmp->set_next(head);
            head->set_pre(tmp);
            head = tmp;
        }
        size++;
    }
    void push_back(int val) {
        node *tmp = new node(val);
        if (size == 0){
            head = tmp;
            tail = tmp;
        }
        else {
            tail->set_next(tmp);
            tmp->set_pre(tail);
            tail = tmp;
        }
        size++;
    }
    int pop_front() {
        if (size == 0) return -1;
        node *del = head;
        int value = head->get_val();
        if (size > 1){
            head = head->get_next();
            head->set_pre(nullptr);
            delete del;
        }
        size--;
        return value;
    }
    int pop_back() {
        if (size == 0) return -1;
        node *del = tail;
        int value = tail->get_val();
        if (size > 1){
            tail = tail->get_pre();
            tail->set_next(nullptr);
            delete del;
        }
        size--;
        return value;
    }
    int get_size() { return size; }
    int get_empty() { return (size > 0 ? 0 : 1); }
    int get_front() { return (size > 0 ? head->get_val() : -1); }
    int get_back() { return (size > 0 ? tail->get_val() : -1); }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string str;
    deque Q;
    int val;
    while (N--)
    {
        cin >> str;

        if (str == "push_front")
        {
            cin >> val;
            Q.push_front(val);
        }
        else if (str == "push_back")
        {
            cin >> val;
            Q.push_back(val);
        }
        else if (str == "pop_front")
        {
            cout << Q.pop_front() << '\n';
        }
        else if (str == "pop_back")
        {
            cout << Q.pop_back() << '\n';
        }
        else if (str == "size")
        {
            cout << Q.get_size() << '\n';
        }
        else if (str == "empty")
        {
            cout << Q.get_empty() << '\n';
        }
        else if (str == "front")
        {
            cout << Q.get_front() << '\n';
        }
        else if (str == "back")
        {
            cout << Q.get_back() << '\n';
        }
        else 
        {
            N++;
            continue;
        }
    }

    return 0;
}