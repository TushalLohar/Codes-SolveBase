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

const int N = 200010;

int n, a[N], b[N], p[N], ans;

void solve() {
    int i, j;

    cin >> n;

    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = 0;
    }

    for (i = 1; i <= n; ++i) {
        cin >> b[i];
        p[b[i]] = i;
    }

    if (p[1]) {
        for (i = 2; p[i] == p[1] + i - 1; ++i);

        if (p[i - 1] == n) {
            for (j = i; j <= n && p[j] <= j - i; ++j);

            if (j > n) {
                cout << n - i + 1;
                return;
            }
        }
    }

    for (i = 1; i <= n; ++i)
        ans = max(ans, p[i] - i + 1 + n);

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}