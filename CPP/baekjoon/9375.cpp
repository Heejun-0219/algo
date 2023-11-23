#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    while (N--)
    {
        int clothes_count;
        cin >> clothes_count;

        map<string, int> clothes;
        for (int i = 0; i < clothes_count; i++) {
            string item;
            string category;

            cin >> item >> category;

            if (clothes.find(category) == clothes.end()) {
                clothes[category] = 0;
            }
            
            clothes[category]++;
        }

        int sum = 1;
        for (const auto& val : clothes) {
            sum *= (val.second + 1);
        }
        cout << sum - 1 << '\n';

        clothes.clear();
    }

    return 0;
}