#include <iostream>
#include <queue>

using namespace std;

struct Compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<pair<int,int>, vector<pair<int, int> >, Compare> pq;
    int time = 0;
    while (n--)
    {
        int input, tax;
        cin >> input >> tax;

        pq.push(make_pair(input, tax));
    }

    while (pq.size())
    {
        pair<int, int> tmp = pq.top();
        pq.pop();

        if (tmp.first > time) time = tmp.first;
        time += tmp.second;
    }
    
    cout << time << endl;    

    return 0;
}