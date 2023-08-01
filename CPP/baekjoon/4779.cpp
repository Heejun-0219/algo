#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

void remove_mid(string *str, int start, int end){
    while (start <= end)
    {
        str->at(start++) = ' ';
    }
}

void divid(string *str, int start, int end){
    int fir, sec;
    if (start + 2 <= end){
        fir = start + (end - start) / 3;
        sec = end - (end - start) / 3;
        divid(str, start, fir);
        remove_mid(str, fir + 1, sec - 1);
        divid(str, sec, end);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long value;

    while (cin >> N){
        value = 1;
        while (N--)
        {
            value *= 3;
        }
        
        string* str = new string();
        while (value--)
        {
            *str += "-";
        }

        divid(str, 0, str->length() - 1);

        cout << *str << endl;
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <cmath>

// using namespace std;

// void cantor_set(string& str, int start, int end, int depth) {
//     if (depth == 0) {
//         return;
//     }

//     int third = (end - start) / 3;
//     for (int i = start + third; i < start + 2 * third; i++) {
//         str[i] = ' ';
//     }

//     cantor_set(str, start, start + third, depth - 1);
//     cantor_set(str, start + 2 * third, end, depth - 1);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     int n;
//     while(cin >> n) {
//         string str(pow(3, n), '-');
//         cantor_set(str, 0, str.size(), n);
//         cout << str << '\n';
//     }

//     return 0;
// }
