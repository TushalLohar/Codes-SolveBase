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

const int N = 200005;

int a[N], b[N];

void solve() {
    int n, k, sum = 0, mxx = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    a[0] = a[n + 1] = a[b[1]];
    b[k + 1] = n + 1;

    for (int i = 0; i <= k; i++) {
        int mx = 0;

        for (int j = b[i]; j < b[i + 1]; j++) {
            if (a[j] != a[j + 1]) mx++;
        }

        sum += mx;
        mxx = max(mxx, mx);
    }

    cout << max(mxx, sum / 2) << "\n";
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