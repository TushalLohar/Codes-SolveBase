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
    int n, f;
    cin >> n >> f;

    long long p = f, g = 0, s = 0;

    for (int i = 1; i < n; i++) {
        int a, c;
        cin >> a;
        c = abs(a - p);
        s += c;
        g = gcd(g, c);
        p = a;
    }

    if (g == 0)
        cout << f << "\n";
    else
        cout << ((f - 1) % (2 * g)) + 1 + s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}