class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> map(nums.begin(), nums.end());
        int ans = k;
        while (map.count(ans)) {
            ans += k;
        }
        return ans;
    }
};