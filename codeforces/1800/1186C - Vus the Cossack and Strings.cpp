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
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    int t = 0, x = 0, y = 0;

    for (int i = 0; i < m; i++)
        if (a[i] != b[i]) ++t;

    for (int i = 0; i < m - 1; i++) {
        if (b[i] != b[i + 1]) {
            x++;
            if (a[i] != b[i]) ++y;
        }
    }

    int ans = 0;

    if (t % 2 == 0) ++ans;

    for (int i = m; i < n; i++) {
        if (a[i] != b[m - 1]) ++t;
        if (a[i - m] != b[0]) --t;

        t -= y;
        t += (x - y);
        y = x - y;

        if (t % 2 == 0) ++ans;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}