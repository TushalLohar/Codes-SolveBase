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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll m = 2 * n;

    vector<int> finalState(m, 0);

    for (ll i = 0; i < m; i++) {
        if (s[i] == '1') {
            ll nxt = (i + 1) % m;

            if (s[nxt] == '0')
                finalState[nxt] = 1;
            else
                finalState[i] = 1;
        }
    }

    ll redScore = 0;
    ll blueScore = 0;

    for (ll i = 0; i < m; i++) {
        if (finalState[i]) {
            if (i % 2 == 0)
                blueScore++;
            else
                redScore++;
        }
    }

    cout << redScore << " " << blueScore << '\n';
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