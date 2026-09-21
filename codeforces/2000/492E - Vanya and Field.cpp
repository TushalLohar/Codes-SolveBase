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
    int n, m, dx, dy;
    cin >> n >> m >> dx >> dy;

    vector<int> f(n);

    int p = 0, q = 0;

    for (int i = 0; i < n; i++) {
        f[p] = q;
        p = (p + dx) % n;
        q = (q + dy) % n;
    }

    vector<int> v(n, 0);

    while (m--) {
        int x, y;
        cin >> x >> y;

        int k = (y - f[x] + n) % n;
        v[k]++;
    }

    int ans = -1;
    int maxn = -1;

    for (int i = 0; i < n; i++) {
        if (v[i] > maxn) {
            maxn = v[i];
            ans = i;
        }
    }

    cout << 0 << ' ' << ans;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}