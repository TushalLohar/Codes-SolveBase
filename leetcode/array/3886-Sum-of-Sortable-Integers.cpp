class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        auto fun = [&](int x) -> bool {
            int prev = -1e9;
            for (int i = 0; i < n; i += x) {
                int cnt = 0;
                for (int k = i; k + 1 < i + x; k++) {
                    if (nums[k] > nums[k + 1]) {
                        ++cnt;
                    }
                }
                if (nums[i + x - 1] > nums[i]) {
                    ++cnt;
                }
                if (cnt > 1) return false;

                int minm = *min_element(nums.begin() + i,
                                        nums.begin() + i + x);

                int maxm = *max_element(nums.begin() + i,
                                        nums.begin() + i + x);

                if (prev > minm) return false;
                prev = maxm;
            }
            return true;
        };
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (fun(i)) ans += i;

                if (i * i != n) {
                    if (fun(n / i)) ans += n / i;
                }
            }
        }
        return ans;
    }
};