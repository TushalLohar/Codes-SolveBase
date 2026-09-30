class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int i = 0;
        vector<int> ans;
        for (char& c : seq)
            if (c == '(') {
                i++;
                ans.push_back(i % 2);
            } else {
                ans.push_back(i % 2);
                i--;
            }
        return ans;
    }
};