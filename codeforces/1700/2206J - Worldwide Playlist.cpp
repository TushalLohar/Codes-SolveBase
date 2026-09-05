#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, queries, answer = 0;
    cin >> n >> queries;
    queries--;

    vector<int> enterOrder(n + 1), exitOrder(n + 1);
    vector<int> enterPos(n + 1), exitPos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> enterOrder[i];
        enterPos[enterOrder[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> exitOrder[i];
        exitPos[exitOrder[i]] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (enterPos[exitOrder[i]] < enterPos[exitOrder[i - 1]])
            answer++;
    }

    cout << answer * n - (n - enterPos[exitOrder[n]]) << "\n";

    while (queries--) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            set<int> affected;

            int posX = exitPos[enterOrder[x]];
            int posY = exitPos[enterOrder[y]];

            if (posX > 1) affected.insert(posX);
            if (posX < n) affected.insert(posX + 1);
            if (posY > 1) affected.insert(posY);
            if (posY < n) affected.insert(posY + 1);

            for (int pos : affected) {
                if (enterPos[exitOrder[pos - 1]] > enterPos[exitOrder[pos]])
                    answer--;
            }

            swap(enterPos[enterOrder[x]], enterPos[enterOrder[y]]);
            swap(enterOrder[x], enterOrder[y]);

            for (int pos : affected) {
                if (enterPos[exitOrder[pos - 1]] > enterPos[exitOrder[pos]])
                    answer++;
            }

            cout << answer * n - (n - enterPos[exitOrder[n]]) << "\n";
        }
        else {
            set<int> affected;

            if (x > 1) affected.insert(x);
            if (x < n) affected.insert(x + 1);
            if (y > 1) affected.insert(y);
            if (y < n) affected.insert(y + 1);

            for (int pos : affected) {
                if (enterPos[exitOrder[pos - 1]] > enterPos[exitOrder[pos]])
                    answer--;
            }

            swap(exitPos[exitOrder[x]], exitPos[exitOrder[y]]);
            swap(exitOrder[x], exitOrder[y]);

            for (int pos : affected) {
                if (enterPos[exitOrder[pos - 1]] > enterPos[exitOrder[pos]])
                    answer++;
            }

            cout << answer * n - (n - enterPos[exitOrder[n]]) << "\n";
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    solve();

    return 0;
}