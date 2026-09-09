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

const ll x = 1e12;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int cnt0 = 0, cnt1 = count(s.begin(), s.end(), '1');
    ll ans = 1e18;

    if (n == 1) ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        cnt0 += s[i] == '0';
        cnt1 -= s[i] == '1';

        int k = cnt0 + cnt1 + (s[i] == '1') + (s[i + 1] == '0');

        ll cur = (n - k) * (x + 1);

        if (s[i] > s[i + 1]) cur += x;

        ans = min(ans, cur);
    }

    cout << ans << '\n';
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