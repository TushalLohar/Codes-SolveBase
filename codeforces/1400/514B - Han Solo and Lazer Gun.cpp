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
#include <chrono>
#include <random>

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

mt19937_64 randll(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    set<pair<ll, ll>> st;

    for (ll i = 0; i < n; i++) {
        ll X, Y;
        cin >> X >> Y;

        ll dx = x - X;
        ll dy = y - Y;

        ll g = __gcd(dx, dy);

        dx /= g;
        dy /= g;

        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        else if (dx == 0 && dy == 0) {
            dy = -dy;
        }

        st.insert({dx, dy});
    }

    cout << st.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}