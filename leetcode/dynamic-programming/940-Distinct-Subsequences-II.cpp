class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        vector<long long> last(26, 0);
        long long total = 1;

        for (char c : s) {
            int x = c - 'a';

            long long old = total;
            total = (2 * total - last[x] + MOD) % MOD;
            last[x] = old;
        }

        return (total - 1 + MOD) % MOD;
    }
};