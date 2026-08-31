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

    vector<int> a(n), b(n);

    for (int &x : a) cin >> x;

    vector<int> skip;
    int p = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > p) {
            for (int x = p + 1; x < a[i]; x++)
                skip.push_back(x);
        }
        p = a[i];
    }

    p = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == p) {
            if (j < skip.size())
                b[i] = skip[j++];
            else
                b[i] = 1000000;
        }
        else {
            b[i] = p;
        }

        p = a[i];
    }

    for (int x : b)
        cout << x << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}