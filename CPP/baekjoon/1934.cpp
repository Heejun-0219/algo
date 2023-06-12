#include <iostream>

int get_gcd(int a, int b){
    if (b == 0)
        return a;
    else 
        return get_gcd(b, a % b);
}

int main(){
    int N;
    std::cin >> N;

    int A, B;
    int Min_mul, Max_divisor;
    for (int i = 0; i < N;  i++){
        std::cin >> A >> B;

        Max_divisor = get_gcd(A, B);
        Min_mul = A * B / Max_divisor;

        std::cout << Min_mul << "\n";
    }

    return 0;
}

// #include <iostream>

// // Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
// int gcd(int a, int b) {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// // Function to calculate the least common multiple (LCM)
// int lcm(int a, int b) {
//     return (a * b) / gcd(a, b);
// }

// int main() {
//     int T;
//     std::cin >> T;

//     while (T--) {
//         int A, B;
//         std::cin >> A >> B;

//         int result = lcm(A, B);
//         std::cout << result << std::endl;
//     }

//     return 0;
// }
