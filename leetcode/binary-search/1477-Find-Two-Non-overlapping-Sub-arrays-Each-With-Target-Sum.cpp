class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> bestPrefix(n, INT_MAX);
        int left = 0;
        int sum = 0;
        int bestLength = INT_MAX;
        int answer = INT_MAX;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int length = right - left + 1;
                if (left > 0 && bestPrefix[left - 1] != INT_MAX) {
                    answer = min(answer, length + bestPrefix[left - 1]);
                }
                bestLength = min(bestLength, length);
            }
            bestPrefix[right] = bestLength;
        }
        return answer == INT_MAX ? -1 : answer;
    }
};