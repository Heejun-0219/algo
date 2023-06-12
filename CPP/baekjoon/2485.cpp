#include <iostream>

int get_gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return get_gcd(b, a % b);
}

int get_tree(int len, int divisor){
    int sum = 0;
    while (len > divisor)
    {
        sum++;
        len -= divisor;
    }
    return sum;
}

int main(){
    int N;
    std::cin >> N;
    
    int* road_diff = new int[N - 1];
    int before, next;
    std::cin >> before;
    for (int i = 0; i < N - 1; i++){
        std::cin >> next;
        road_diff[i] = next - before;
        before = next;
    }

    int Max_divisor = get_gcd(road_diff[0], road_diff[1]);
    for (int i = 2; i < N - 2; i++){
        Max_divisor = get_gcd(road_diff[i], Max_divisor);
    }

    int tree = 0;
    for (int i = 0; i < N - 1; i++){
        tree += get_tree(road_diff[i], Max_divisor);
    }

    std::cout << tree;
    return 0;
}