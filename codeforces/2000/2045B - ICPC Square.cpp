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
    ll n, d, s;
    cin >> n >> d >> s;

    if (d < s) {
        cout << s << "\n";
        return;
    }

    n /= s;
    d /= s;

    ll t = min(n, 2 * d);

    for (ll i = 1; i * i <= t; i++) {
        if (t % i != 0) continue;

        ll x = i;
        ll y = t / i;

        if ((x <= d && t - x <= d) ||
            (y <= d && t - y <= d)) {
            cout << t * s << "\n";
            return;
        }
    }

    cout << (t - 1) * s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}