class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());
        bool same = true;
        for (int i = 1; i < nums1.size(); i++) {
            if (nums1[i] % 2 != nums1[0] % 2) {
                same = false;
                break;
            }
        }
        if (same) return true;

        return mn % 2 == 1;
    }
};