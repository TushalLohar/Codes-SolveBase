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

const int N = 1e6 + 10;

ll a[N], y[N], x[N];

void solve() {
    ll n;
    cin >> n;

    ll tar = 0, ans = 0;

    for (ll i = 1; i <= n; i++) {
        cin >> y[i] >> x[i];

        ll cnt = a[i - 1];

        if (tar == cnt || abs(tar - cnt) <= y[i] - y[i - 1])
            a[i] = tar, tar = x[i];
        else {
            ll res = y[i] - y[i - 1];

            if (tar > cnt)
                a[i] = cnt + res;
            else
                a[i] = cnt - res;
        }
    }

    a[n + 1] = tar;

    for (ll i = 1; i <= n; i++)
        if (min(a[i], a[i + 1]) <= x[i] &&
            max(a[i], a[i + 1]) >= x[i])
            ans++;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q;
    cin >> q;

    while (q--) {
        solve();
    }

    return 0;
}