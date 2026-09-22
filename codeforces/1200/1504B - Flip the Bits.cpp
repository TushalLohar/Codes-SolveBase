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

    string a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "YES" << endl;
        return;
    }

    vector<bool> can_flip(n);
    int one = 0, zero = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            zero++;
        } else {
            one++;
        }

        if (one == zero) {
            can_flip[i] = true;
        }
    }

    bool isFlip = false;
    bool isPoss = true;

    for (int i = n - 1; i >= 0; i--) {
        if (!isFlip) {
            if (a[i] != b[i]) {
                if (can_flip[i]) {
                    isFlip ^= true;
                } else {
                    isPoss = false;
                    break;
                }
            }
        } else {
            if (a[i] == b[i]) {
                if (can_flip[i]) {
                    isFlip ^= true;
                } else {
                    isPoss = false;
                    break;
                }
            }
        }
    }

    if (isPoss) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}