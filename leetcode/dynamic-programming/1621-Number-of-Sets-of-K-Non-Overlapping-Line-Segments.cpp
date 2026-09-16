class Solution {
public:
    long long power(long long a, long long b) {
        long long result = 1;

        while (b) {
            if (b & 1) {
                result = result * a % MOD;
            }

            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }

    static const long long MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        int total = n + k - 1;
        int choose = 2 * k;

        vector<long long> fact(total + 1);

        fact[0] = 1;

        for (int i = 1; i <= total; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        long long numerator = fact[total];
        long long denominator = fact[choose] *
                                fact[total - choose] % MOD;

        long long inverse = power(denominator, MOD - 2);

        return numerator * inverse % MOD;
    }
};