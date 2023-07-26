#include <iostream>
#include <vector>

using namespace std;

class node
{
private:
    int val;
    node *next;
public:
    node(int val) : val(val), next(nullptr) { }
    ~node() { }
    int get_val() { return val; }
    node *get_next() { return next; }
    void set_next(node *next) { this->next = next; }
};

class list
{
private:
    node *head;
    node *tail;
    int size;
public:
    list() : head(nullptr), tail(nullptr), size(0) { }
    ~list() { }
    void push(int val){
        node *insert = new node(val);
        if (size == 0){
            head = insert;
            tail = insert;
        }
        else {
            tail->set_next(insert);
            insert->set_next(head);
            tail = insert;
        }
        size++;
    }
    int pop(int K){
        if (size > 0){
            while (K-- > 1) head = head->get_next();

            node *del = head->get_next();
            int val = del->get_val();
            head->set_next(del->get_next());
            head = head->get_next();
            delete del;
            size--;
            return val;
        }
        return -1;
    }
    int get_size() { return size; }
    int top() { return head->get_val(); }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    list L;
    
    for (int i = 1; i <= N; i++) L.push(i);

    vector<int> val;
    while (L.get_size() > 1)
    {
        val.push_back(L.pop(K - 1));
    }
    val.push_back(L.top());

    cout << "<";
    for (int value : val){
        cout << value;
        if (N-- > 1)
            cout << ", ";
    }
    cout << ">" << endl;

    return 0;
}

// #include <iostream>
// #include <queue>
// using namespace std;

// int main() {
//     int N, K;
//     cin >> N >> K;

//     queue<int> q;
//     for (int i = 1; i <= N; i++) {
//         q.push(i);
//     }

//     cout << "<";
//     while (!q.empty()) {
//         for (int i = 0; i < K - 1; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//         cout << q.front();
//         q.pop();

//         if (!q.empty()) {
//             cout << ", ";
//         }
//     }
//     cout << ">";

//     return 0;
// }
