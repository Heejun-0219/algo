#include <iostream>
#include <math.h>

using namespace std;

int n, m;
int a[5][5];
int ret;
int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    for (int k = 0; k < (1 << (n * m)); k++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                int tmp = i * m + j;
                if ((k & (1 << tmp)) == 0) {
                    cur = cur * 10 + a[i][j];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for (int i = 0; i < m; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                int tmp = j * m + i;
                if ((k & (1 << tmp)) != 0) {
                    cur = cur * 10 + a[j][i];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret, sum);
    }

    cout << ret << endl;

    return 0;
}
