class Solution {
public:
    bool checkDivisibility(int n) {
        int digit_sum = 0;
        int digitProduct = 1;
        int og = n;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            digit_sum += digit;
            digitProduct *= digit;
        }

        return og% (digit_sum + digitProduct) == 0;
    }
};