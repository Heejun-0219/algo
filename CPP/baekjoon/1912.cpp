#include <iostream>
#include <vector>

using namespace std;

int maxContiguousSum(vector<int>& arr) {
    int n = arr.size();
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < n; ++i) {
        // 현재 위치에서의 최대 연속합 계산
        current_sum = max(arr[i], current_sum + arr[i]);

        // 전체 최대 연속합 업데이트
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = maxContiguousSum(arr);
    cout << result << endl;

    return 0;
}
