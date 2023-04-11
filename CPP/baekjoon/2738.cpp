#include <iostream>

int main(){
    int m, n;

    std::cin >> m >> n;
    int** a = new int*[m];
    for (int i = 0; i < m; i++){
        a[i] = new int[n];
        for (int j = 0; j < n; j++){
            std::cin >> a[i][j];
        }
    }

    int** b = new int*[m];
    for (int i = 0; i < m; i++){
        b[i] = new int[n];
        for (int j = 0; j < n; j++){
            std::cin >> b[i][j];
        }
    }

    int** c = new int*[m];
    for (int i = 0; i < m; i++){
        c[i] = new int[n];
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}