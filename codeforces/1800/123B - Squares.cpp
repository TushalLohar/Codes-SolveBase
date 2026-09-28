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
    ll a, b, x1, x2, y1, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    ll s1 = x1 + y1, s2 = x2 + y2;
    ll s3 = x1 - y1, s4 = x2 - y2;

    s1 = s1 / (2 * a) + (s1 > 0);
    s2 = s2 / (2 * a) + (s2 > 0);
    s3 = s3 / (2 * b) + (s3 > 0);
    s4 = s4 / (2 * b) + (s4 > 0);

    cout << max(abs(s1 - s2), abs(s3 - s4));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}