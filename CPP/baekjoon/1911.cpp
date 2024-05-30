    // 웅덩이를 시작 위치 기준으로 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    vector<pair<long long, long long>> puddles(n);

    for (int i = 0; i < n; i++) {
        cin >> puddles[i].first >> puddles[i].second;
    }

    sort(puddles.begin(), puddles.end());

    long long currentPos = 0;
    int plankCount = 0;

    for (const auto& puddle : puddles) {
        if (currentPos < puddle.first) {
            currentPos = puddle.first;
        }

        while (currentPos < puddle.second) {
            currentPos += l;
            plankCount++;
        }
    }

    cout << plankCount << "\n";
    return 0;
}
