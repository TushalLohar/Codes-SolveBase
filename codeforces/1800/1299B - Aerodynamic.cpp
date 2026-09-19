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
    const int N = 1e5 + 5;
    int n, a[N], b[N], p, cx, cy;

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    if (n & 1) {
        cout << "NO" << "\n";
        return;
    }

    p = n / 2;
    cx = a[1] + a[p + 1];
    cy = b[1] + b[p + 1];

    for (int i = 2; i <= p; i++) {
        if ((a[i] + a[p + i]) != cx || (b[i] + b[p + i]) != cy) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}