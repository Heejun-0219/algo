#include <iostream>

using namespace std;

int g_k = 0;
int g_count = 0;

void merge(int *Arr, int p, int q, int r){
    // # A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
    // # A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
    // i <- p; j <- q + 1; t <- 1;
    // while (i ≤ q and j ≤ r) {
    //     if (A[i] ≤ A[j])
    //     then tmp[t++] <- A[i++]; # tmp[t] <- A[i]; t++; i++;
    //     else tmp[t++] <- A[j++]; # tmp[t] <- A[j]; t++; j++;
    // }
    // while (i ≤ q)  # 왼쪽 배열 부분이 남은 경우
    //     tmp[t++] <- A[i++];
    // while (j ≤ r)  # 오른쪽 배열 부분이 남은 경우
    //     tmp[t++] <- A[j++];
    // i <- p; t <- 1;
    // while (i ≤ r)  # 결과를 A[p..r]에 저장
    //     A[i++] <- tmp[t++];
    int *tmp = new int[r - p + 1];
    int i = p;
    int j = q + 1;
    int t = 0;
    while (i <= q && j <= r){
        if (Arr[i] <= Arr[j]) {
            tmp[t++] = Arr[i++];
        }
        else
            tmp[t++] = Arr[j++];
    }
    while (i <= q)
    {
        tmp[t++] = Arr[i++];
    }
    while (j <= r)
    {
        tmp[t++] = Arr[j++];
    }
    i = p;
    t = 0;
    while (i <= r)
    {
        Arr[i++] = tmp[t++];
        g_count++;
        if (g_count == g_k)
            cout << tmp[t - 1];
    }
    delete[] tmp;
}

void merge_sort(int *Arr, int p, int r){
    // if (p < r) then {
    //     q <- ⌊(p + r) / 2⌋;       # q는 p, r의 중간 지점
    //     merge_sort(A, p, q);      # 전반부 정렬
    //     merge_sort(A, q + 1, r);  # 후반부 정렬
    //     merge(A, p, q, r);        # 병합
    // }
    int q;
    if (p < r) {
        q = (p + r) / 2;
        merge_sort(Arr, p, q);
        merge_sort(Arr, q + 1, r);
        merge(Arr, p, q, r);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N >> g_k;
    
    int *arr = new int[N];
    int value;
    for (int i = 0; i < N; i++)
    {
        cin >> value;
        arr[i] = value;
    }
    
    merge_sort(arr, 0, N - 1);

    // for (int i = 0; i < N; i++){
    //     cout << arr[i] << " ";
    // }

    if (g_count < g_k)
        cout << -1;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #define ll long long

// using namespace std;

// int n, k;
// int arr[500001], sorted[500001];
// ll save = 0;

// void merge(int left, int mid, int right) {
//     int i = left;
//     int j = mid + 1;
//     int idx = left;

//     while (i <= mid && j <= right) {
//         if (arr[i] <= arr[j]) {
//             sorted[idx++] = arr[i++];
//         }
//         else {
//             sorted[idx++] = arr[j++];
//         }
//         save++;
//         if (save == k) {
//             cout << sorted[idx - 1];
//             exit(0);
//         }
//     }

//     while (i <= mid) {
//         sorted[idx++] = arr[i++];
//         save++;
//         if (save == k) {
//             cout << sorted[idx - 1];
//             exit(0);
//         }
//     }

//     while (j <= right) {
//         sorted[idx++] = arr[j++];
//         save++;
//         if (save == k) {
//             cout << sorted[idx - 1];
//             exit(0);
//         }
//     }

//     for (int t = left; t <= right; t++) {
//         arr[t] = sorted[t];
//     }
// }

// void mergeSort(int left, int right) {
//     int mid;
//     if (left < right) {
//         mid = (left + right) / 2;
//         mergeSort(left, mid);
//         mergeSort(mid + 1, right);
//         merge(left, mid, right);
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> n >> k;

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     mergeSort(0, n - 1);

//     if (save < k) {
//         cout << -1;
//     }

//     return 0;
// }
