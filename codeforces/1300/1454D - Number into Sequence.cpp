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
    ll n;
    cin >> n;

    ll temp = n;
    ll bestPrime = -1;
    int bestCount = 0;

    for (ll p = 2; p * p <= temp; p++) {
        if (temp % p == 0) {
            int count = 0;

            while (temp % p == 0) {
                temp /= p;
                count++;
            }

            if (count > bestCount) {
                bestCount = count;
                bestPrime = p;
            }
        }
    }

    if (temp > 1 && bestCount < 1) {
        bestPrime = temp;
        bestCount = 1;
    }

    cout << bestCount << '\n';

    ll remaining = n;

    for (int i = 0; i < bestCount - 1; i++) {
        cout << bestPrime << ' ';
        remaining /= bestPrime;
    }

    cout << remaining << '\n';
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