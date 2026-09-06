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
    static int a[1000000];

    a[0] = 1e9;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int drops = 0, minimum = 1e9, length = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            drops++;
            length = 1;
        }
        else {
            length++;
        }
    }

    if (drops == 1) {
        cout << "0\n";
        return;
    }

    if (drops == 2) {
        if (a[n] <= a[1])
            minimum = min(minimum, length);

        if (a[1] >= a[n])
            minimum = min(minimum, n - length + 2);
    }

    reverse(a + 1, a + 1 + n);

    drops = 0;
    length = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            drops++;
            length = 1;
        }
        else {
            length++;
        }
    }

    if (drops == 1) {
        cout << "1\n";
        return;
    }

    if (drops == 2) {
        if (a[n] <= a[1])
            minimum = min(minimum, length + 1);

        if (a[1] >= a[n])
            minimum = min(minimum, n - length + 1);
    }

    if (minimum == 1e9)
        cout << "-1\n";
    else
        cout << minimum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}