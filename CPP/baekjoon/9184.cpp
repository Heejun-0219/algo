#include <iostream>
#include <map>
#include <tuple>

using namespace std;

map<tuple<int, int, int>, int> w_map;

void w_print_func(int a, int b, int c){
    cout << "w(" << a << ", " << b << ", " << c << ") = ";
}

int w_cal_func(const int a, const int b, const int c){
    if (w_map.find({a, b, c}) != w_map.end()){
        return w_map[{a, b, c}];
    }
    else if (a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20){
        return w_cal_func(20, 20, 20);
    }
    else if (a < b && b < c) {
        return w_map[{a, b, c}] = w_cal_func(a, b, c-1) + w_cal_func(a, b-1, c-1) - w_cal_func(a, b-1, c);
    }
    else {
        return w_map[{a, b, c}] = w_cal_func(a-1, b, c) + w_cal_func(a-1, b-1, c) + w_cal_func(a-1, b, c-1) - w_cal_func(a-1, b-1, c-1);
    }
    return 0;
}

void w_func(){
    int a, b, c;

    while (true)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;
        
        w_print_func(a, b, c);
        cout << w_cal_func(a, b, c) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    w_func();

    return 0;
}