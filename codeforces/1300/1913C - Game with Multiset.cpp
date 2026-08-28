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
    int m;
    cin >> m;

    long long cnt[30] = {};

    while (m--) {
        int type;
        long long v;
        cin >> type >> v;

        if (type == 1) {
            cnt[v]++;
        }
        else {
            long long w = v;

            for (int x = 29; x >= 0; x--) {
                long long value = (1LL << x);
                long long take = min(cnt[x], w / value);

                w -= take * value;
            }

            if (w == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}