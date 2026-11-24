
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1, l = 1;
            int g = 0;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = l / gcd(l, nums[j]) * nums[j];

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }

                if (prod > 25200) {
                    break;
                }
            }
        }

        return ans;
    }
};
