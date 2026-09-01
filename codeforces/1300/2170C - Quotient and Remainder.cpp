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

    vector<ll> q(n), r(n);

    for (ll& i : q)
        cin >> i;

    for (ll& i : r) {
        cin >> i;
        i = max(0ll, k - i) / (i + 1);
    }

    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    ll i = 0;

    for (ll j = 0; j < n; ++j)
        if (q[i] <= r[j])
            ++i;

    cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}