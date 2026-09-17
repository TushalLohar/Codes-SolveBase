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
    int n, k, k1 = -2e9;
    cin >> n >> k;

    vector<int> cnt(n);
    string s, st;
    cin >> s >> st;

    int i = n - 1, j = n - 1;

    while (i >= 0 && j >= 0) {
        if (i < j) j = i;

        while (s[j] != st[i] && j >= 0) j--;

        if (i - j > k || j < 0) {
            cout << -1 << "\n";
            return;
        }

        cnt[i] = i - j;
        k1 = max(k1, i - j);
        i--;
    }

    cout << k1 << "\n";

    while (k1--) {
        for (int i = n - 1; i >= 0; i--) {
            if (cnt[i] > 0) {
                s[i] = s[i - 1];
                cnt[i]--;
            }
        }

        cout << s << "\n";
    }
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