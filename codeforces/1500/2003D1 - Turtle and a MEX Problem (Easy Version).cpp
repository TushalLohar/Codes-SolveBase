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
    ll n, m, l, mx;
    cin >> n >> m;
    mx = 0;

    for (int i = 1; i <= n; i++) {
        cin >> l;

        set<ll> a;
        int f = 0;

        for (int j = 1; j <= l; j++) {
            ll x;
            cin >> x;
            a.insert(x);
        }

        for (ll j = 0;; j++) {
            if (a.find(j) == a.end()) {
                if (!f) f = 1;
                else {
                    mx = max(mx, j);
                    break;
                }
            }
        }
    }

    if (mx >= m)
        cout << mx * (m + 1) << "\n";
    else
        cout << (mx + 1) * mx + (m - mx) * (m + mx + 1) / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}