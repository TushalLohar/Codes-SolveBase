#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <list>
#include <numeric>
#include <iomanip>
#include <climits>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define pb push_back
#define ff first
#define ss second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;

    if (k == n - 1) {
        if (n == 4) {
            cout << -1 << '\n';
            return;
        }

        cout << n - 1 << " " << n - 2 << '\n';
        cout << 1 << " " << n - 3 << '\n';
        cout << 0 << " " << 2 << '\n';

        vector<bool> visited(n, false);
        visited[n - 1] = visited[n - 2] = true;
        visited[1] = visited[n - 3] = true;
        visited[0] = visited[2] = true;

        for (ll i = 0; i < n; i++) {
            if (!visited[i]) {
                ll comp = (n - 1) - i;
                cout << i << " " << comp << '\n';
                visited[i] = visited[comp] = true;
            }
        }

        return;
    }

    if (k == 0) {
        for (ll i = 0; i < n / 2; i++) {
            cout << i << " " << (n - i - 1) << '\n';
        }

        return;
    }

    vector<bool> visited(n, false);

    cout << k << " " << n - 1 << '\n';
    cout << 0 << " " << ((n - 1) - k) << '\n';

    visited[k] = visited[n - 1] = true;
    visited[0] = visited[(n - 1) - k] = true;

    for (ll i = 0; i < n; i++) {
        if (!visited[i]) {
            ll comp = (n - 1) - i;
            cout << i << " " << comp << '\n';
            visited[i] = visited[comp] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}