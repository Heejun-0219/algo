#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int countGoldbachPartitions(int n, const vector<int>& primes) {
    int count = 0;

    for (int i = 0; primes[i] <= n / 2; ++i) {
        int complement = n - primes[i];
        if (binary_search(primes.begin(), primes.end(), complement)) {
            count++;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;

    const int MAX_N = 1000000;
    vector<int> primes = getPrimes(MAX_N);

    while (T--) {
        int N;
        cin >> N;

        int result = countGoldbachPartitions(N, primes);
        cout << result << endl;
    }

    return 0;
}
