#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

vector<string> V;
int g_count = 0;

void move(int from, int to)
{
    string value = to_string(from) + " " + to_string(to);
    V.push_back(value);
    g_count++;
}

void hanoi(int n, int from, int by, int to)
{
    if(n == 0) return;
    hanoi(n - 1, from, to, by);
    move(from, to);
    hanoi(n - 1, by, from, to);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    hanoi(n, 1, 2, 3);

    cout << g_count << '\n';
    for (auto str : V){
        cout << str << '\n';
    }

    return 0;
}

// #include<iostream>
// #include<vector>
// using namespace std;

// vector<pair<int, int>> moves;

// void Hanoi(int n, int from, int by, int to) {
//     if (n == 1) {
//         moves.push_back(make_pair(from, to));
//     } else {
//         Hanoi(n - 1, from, to, by);
//         moves.push_back(make_pair(from, to));
//         Hanoi(n - 1, by, from, to);
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N;
//     cin >> N;
    
//     Hanoi(N, 1, 2, 3);
    
//     cout << moves.size() << "\n";
//     for (int i = 0; i < moves.size(); i++) {
//         cout << moves[i].first << " " << moves[i].second << "\n";
//     }

//     return 0;
// }
