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

    string s(n, '0');

    if (n <= 2) {
        for (int i = 0; i < n; i++)
            s[i] = '1';

        cout << s << '\n';
        return;
    }

    int k = n / 6;
    int r = n % 6;

    if (r == 2) {
        s[0] = '1';
        s[2 * k + 1] = '1';
        s[4 * k + 1] = '1';
    }
    else {
        int p1, p2;

        if (r == 0) {
            p1 = 2 * k;
            p2 = 4 * k;
        }
        else if (r == 1) {
            p1 = 2 * k + 1;
            p2 = 4 * k + 1;
        }
        else if (r == 3) {
            p1 = 2 * k + 1;
            p2 = 4 * k + 3;
        }
        else if (r == 4) {
            p1 = 2 * k + 1;
            p2 = 4 * k + 3;
        }
        else {
            p1 = 2 * k + 2;
            p2 = 4 * k + 4;
        }

        s[p1 - 1] = '1';
        s[p2 - 1] = '1';
    }

    cout << s << '\n';
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