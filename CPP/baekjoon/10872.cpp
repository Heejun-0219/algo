#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    if (N == 0)
        std::cout << 1;
    else
    {
        long long int val = 1;

        for (int i = 1; i <= N; i++)
        {
            val *= i;
        }

        std::cout << val;
    }

    return 0;
}

// #include<iostream>
// using namespace std;

// int factorial(int n) {
//     if (n <= 1) return 1;
//     else return n * factorial(n-1);
// }

// int main(){
//     int N;
//     cin >> N;
//     cout << factorial(N);
//     return 0;
// }
