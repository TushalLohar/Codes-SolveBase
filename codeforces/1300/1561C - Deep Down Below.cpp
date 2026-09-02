#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        int n;
        cin >> n;

        vector<pair<long long, int>> caves;

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;

            long long need = 0;

            for (int j = 0; j < k; j++) {
                long long armor;
                cin >> armor;

                need = max(need, armor - j + 1);
            }

            caves.push_back({need, k});
        }

        sort(caves.begin(), caves.end());

        long long defeated = 0;
        long long answer = 0;

        for (auto [need, monsters] : caves) {
            answer = max(answer, need - defeated);
            defeated += monsters;
        }

        cout << answer << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        Solution s;
        s.solve();
    }

    return 0;
}