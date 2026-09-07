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

int n, k, T;
string s;

int solve() {
    cin >> n >> k >> s;

    vector<int> v;
    int sum = 0;

    for (int i = n - 1; i > 0; --i) {
        sum += (s[i] == '1' ? 1 : -1);

        if (sum > 0)
            v.push_back(sum);
    }

    sort(v.begin(), v.end(), greater<int>());

    int ans = 0;

    for (int i = 0; i < v.size(); i++) {
        ans += v[i];

        if (ans >= k)
            return i + 2;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--)
        cout << solve() << "\n";

    return 0;
}