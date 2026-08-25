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
    char c;
    cin >> n >> c;

    string s;
    cin >> s;

    bool allSame = true;

    for (int i = 0; i < n; i++) {
        if (s[i] != c) {
            allSame = false;
            break;
        }
    }

    if (allSame) {
        cout << 0 << '\n';
        return;
    }

    int answer = -1;

    for (int i = 2; i <= n; i++) {
        bool possible = true;

        for (int j = i; j <= n; j += i) {
            if (s[j - 1] != c) {
                possible = false;
                break;
            }
        }

        if (possible) {
            answer = i;
            break;
        }
    }

    if (answer != -1) {
        cout << 1 << '\n';
        cout << answer << '\n';
        return;
    }

    cout << 2 << '\n';
    cout << n - 1 << " " << n << '\n';
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