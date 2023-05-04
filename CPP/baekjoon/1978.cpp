#include <iostream>
using namespace std;

int main(){
    int N;

    cin >> N;

    int k;
    int c = 0;
    while (N--)
    {
        cin >> k;
        if (k == 3 || k == 2) c++;
        else {   
            for (int i = 2; i <= k/2; i++)
            {
                if (k % i == 0) {
                    break;
                }
                else if (i == k/2) c++;
            }   
        }
    }
    cout << c << endl;
    return 0;
}