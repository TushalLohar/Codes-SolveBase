#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long c;
        cin >> c;

        int k = 64 - __builtin_clzll(c);

        long long a = c;
        long long b = c << k;

        cout << a << " " << b << '\n';
    }

    return 0;
}