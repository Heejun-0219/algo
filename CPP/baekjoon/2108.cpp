#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

int find_mode(std::vector<int>& A){
    std::map<int, int> frequeny;

    for (int num : A){
        frequeny[num]++;
    }

    int mode = 0;
    int max_fre = 0;

    for (const auto& p : frequeny){
        if (p.second > max_fre){
            max_fre = p.second;
            mode = p.first;
        }
    }

    std::set<int> f;
    f.insert(mode);
    for (const auto& p : frequeny){
        if (max_fre == p.second){
            f.insert(p.first);
        }
    }

    std::vector<int> tmp;
    tmp.assign(f.begin(), f.end());
    if (tmp.size() > 1)
        return tmp[1];
    else
        return mode;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> A;
    int tmp;
    double sum = 0;
    for (int i = 0; i < N; i++){
        std::cin >> tmp;
        A.push_back(tmp);
        sum += tmp;
    }

    std::sort(A.begin(), A.end());

    int mean, mid, mode, range;
    double mean_under;

    mean_under = sum / A.size();
    mean = std::round(mean_under);

    if (A.size() % 2) mid = A[A.size() / 2];
    else mid = A[A.size() / 2 - 1];

    mode = find_mode(A);

    if (A.size() > 1)
        range = A[A.size() - 1] - A[0];
    else
        range = 0;

    std::cout << mean << "\n" << mid << "\n" << mode << "\n" << range;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <map>
// #include <set>
// #include <cmath>

// // 최빈값을 찾는 함수
// int find_mode(std::vector<int>& A){
//     std::map<int, int> frequency;

//     // 각 원소의 빈도수를 계산
//     for (int num : A){
//         frequency[num]++;
//     }

//     int mode = 0;
//     int max_frequency = 0;

//     // 가장 높은 빈도수를 가진 숫자를 찾음
//     for (const auto& p : frequency){
//         if (p.second > max_frequency){
//             max_frequency = p.second;
//             mode = p.first;
//         }
//     }

//     std::set<int> f;
//     f.insert(mode);

//     // 최빈값들을 set에 추가
//     for (const auto& p : frequency){
//         if (max_frequency == p.second){
//             f.insert(p.first);
//         }
//     }

//     std::vector<int> tmp;
//     tmp.assign(f.begin(), f.end());

//     if (tmp.size() > 1)
//         return tmp[1]; // 최빈값이 둘 이상인 경우 두 번째로 작은 값을 반환
//     else
//         return mode; // 그 외의 경우, 최빈값을 반환
// }

// int main(){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int N;
//     std::cin >> N;

//     std::vector<int> A(N);
//     double sum = 0;
//     for (int i = 0; i < N; i++){
//         std::cin >> A[i];
//         sum += A[i];
//     }

//     std::sort(A.begin(), A.end());

//     int mean, median, mode, range;

//     // 산술평균 계산
//     mean = std::round(sum / A.size());

//     // 중앙값 계산
//     median = A[N / 2];

//     // 최빈값 계산
//     mode = find_mode(A);

//     // 범위 계산
//     range = (N > 1) ? A[N - 1] - A[0] : 0;

//     std::cout << mean << "\n" << median << "\n" << mode << "\n" << range;
// }
