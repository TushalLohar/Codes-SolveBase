class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int pos = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool inc = true, dec = true;

        for (int i = 1; i < n; i++) {
            int x = nums[(pos + i) % n];
            if (x != i) inc = false;
            if (x != n - i) dec = false;
            if (!inc && !dec) return -1;
        }

        if (inc) return min(pos, n - pos + 2);
        return min(n - pos, pos + 2);
    }
};