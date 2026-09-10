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

    vector<double> a(n);
    vector<int> b(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = floor(a[i]);
        sum += b[i];
    }

    for (int i = 0; i < n && sum < 0; i++) {
        if (b[i] != ceil(a[i])) {
            b[i]++;
            sum++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}