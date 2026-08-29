class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());

        int currGroup = 0;
        unordered_map<int, int> numToGroup;
        numToGroup.insert({numsSorted[0], currGroup});

        unordered_map<int, list<int>> groupToList;
        groupToList[currGroup].push_back(numsSorted[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (abs(numsSorted[i] - numsSorted[i - 1]) > limit) {
                currGroup++;
            }

            numToGroup.insert({numsSorted[i], currGroup});
            groupToList[currGroup].push_back(numsSorted[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = numToGroup[num];

            nums[i] = groupToList[group].front();
            groupToList[group].pop_front();
        }

        return nums;
    }
};