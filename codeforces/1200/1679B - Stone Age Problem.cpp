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
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> values(n, {0, 0});

    for (int i = 0; i < n; i++)
        cin >> values[i].first;

    pair<int, int> globalValue = {0, -1};

    ll sum = 0;

    for (int i = 0; i < n; i++)
        sum += values[i].first;

    for (int query = 1; query <= q; query++) {
        int type;
        cin >> type;

        if (type == 1) {
            int index, value;
            cin >> index >> value;

            index--;

            if (values[index].second > globalValue.second)
                sum += value - values[index].first;
            else
                sum += value - globalValue.first;

            values[index].first = value;
            values[index].second = query;
        }
        else {
            int value;
            cin >> value;

            globalValue.first = value;
            globalValue.second = query;

            sum = 1LL * value * n;
        }

        cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}