#include <iostream>
using namespace std;

int n;
int set;
char oper[11];
int value;
int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", &oper, &value);

        if (oper[0] == 'a' && oper[1] == 'd') {
            set |= (1 << value);
        }
        else if (oper[0] == 'r') {
            set &= ~(1 << value);
        }
        else if (oper[0] == 'c') {
            printf("%d\n", ((set & (1 << value)) ? 1 : 0));
        }
        else if (oper[0] == 't') {
            set ^= (1 << value);
        }
        else if (oper[0] == 'a') {
            set |= (1 << 21) - 1;
        }
        else if (oper[0] == 'e') {
            set &= ~((1 << 21) - 1);
        }
    }

    return 0;
}
