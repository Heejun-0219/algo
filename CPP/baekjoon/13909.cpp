#include <iostream>
#include <cmath>

inline bool getDivisor(int val)
{
    int div_count = 0;

    for (int i = 1; i <= sqrt(val); i++)
    {
        if (val % i == 0)
        {
            div_count += 2;

            if (i == val / i)
                div_count--;
        }
    }

    return (div_count % 2 == 0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (getDivisor(i))
            count++;
    }
    std::cout << count;
    return 0;
}

// #include <iostream>

// using namespace std;

// int main() {
//  int n, i;
// 	cin >> n;
// 	while (i * i <= n) i++;
// 	cout << i - 1 << endl;
// }
