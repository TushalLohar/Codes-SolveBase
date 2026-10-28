class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<bitset<1024>> a(n);
        a[0][grid[0][0]] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                bitset<1024> b;

                for (int k = 0; k < 1024; k++) {
                    if ((i > 0 && a[j][k]) ||
                        (j > 0 && a[j - 1][k])) {
                        b[k ^ grid[i][j]] = 1;
                    }
                }

                a[j] = b;
            }
        }

        for (int k = 0; k < 1024; k++) {
            if (a[n - 1][k]) return k;
        }

        return -1;
    }
};