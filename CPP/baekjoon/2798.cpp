#include <iostream>
using namespace std;

int max = 0;
int N = 0;
int M = 0;

void bfs(int sum, int count, int current_pos, int* card){
    if (sum > M)
        return ;
    else if (count == 3){
        if (::max < sum) ::max = sum;
    }
    else{
        for (int i = current_pos; i < N; i++) {
            bfs(sum + card[i], count+1, i+1, card);
        }
    }
}

int main(){
    cin >> N >> M;
    // size N new array
    int* card = new int[N];
    
    for (int i = 0; i < N; i++)
        cin >> card[i];

    bfs(0, 0, 0, card);

    // print ::max
    cout << ::max << endl;

    // delete array
    delete[] card;
    return 0;
}