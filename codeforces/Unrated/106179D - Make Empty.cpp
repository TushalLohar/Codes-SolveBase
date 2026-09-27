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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int k = n / 2;

    bool ok = true;

    for (int i = 0; i < k; i++) {
        if (a[i] > k) {
            ok = false;
            break;
        }
    }

    if (ok) {
        for (int i = k; i < n; i++) {
            if (a[i] <= k) {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        cout << 1 << '\n';
        cout << n << ' ';

        for (int x : a)
            cout << x << ' ';

        cout << '\n';
        return;
    }

    ok = true;

    for (int i = 0; i < k; i++) {
        if (a[i] <= k) {
            ok = false;
            break;
        }
    }

    if (ok) {
        for (int i = k; i < n; i++) {
            if (a[i] > k) {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        cout << 1 << '\n';
        cout << n << ' ';

        for (int x : a)
            cout << x << ' ';

        cout << '\n';
        return;
    }

    vector<int> first, second;

    for (int i = 0; i < k; i++) {
        if (a[i] <= k)
            first.pb(a[i]);
        else
            second.pb(a[i]);
    }

    for (int i = k; i < n; i++) {
        if (a[i] > k)
            first.pb(a[i]);
        else
            second.pb(a[i]);
    }

    cout << 2 << '\n';

    cout << first.size() << ' ';
    for (int x : first)
        cout << x << ' ';
    cout << '\n';

    cout << second.size() << ' ';
    for (int x : second)
        cout << x << ' ';
    cout << '\n';
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