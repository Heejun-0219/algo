#include <iostream>
using namespace std;

int main(){
    int N, K;
    int cnt = 1;

    cin >> N >> K;
    while (true)
    {
      if (N % cnt == 0) K--;
      else if (N <= cnt) {
        cnt = 0;
        break;
      }
      if (K == 0) break;
      cnt++;
    }
    cout << cnt << endl;
    return 0;
}