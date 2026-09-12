class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<tuple<int, int, int, int>> arr;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int weight = intervals[i][2];

            arr.emplace_back(start, end, weight, i);
        }
        sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
            return get<1>(a) < get<1>(b);
        });
        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        vector<vector<vector<int>>> indices(n + 1, vector<vector<int>>(5));
        for (int i = 0; i < n; i++) {
            auto [start, end, weight, index] = arr[i];

            int prev = lower_bound(
                arr.begin(),
                arr.begin() + i,
                start,
                [](auto& interval, int value) {
                    return get<1>(interval) < value;
                }
            ) - arr.begin();

            for (int count = 1; count <= 4; count++) {
                long long skip = dp[i][count];
                long long take = dp[prev][count - 1] + weight;

                if (skip > take) {
                    dp[i + 1][count] = skip;
                    indices[i + 1][count] = indices[i][count];
                } else {
                    vector<int> current = indices[prev][count - 1];
                    current.push_back(index);
                    sort(current.begin(), current.end());

                    if (skip == take && indices[i][count] < current) {
                        current = indices[i][count];
                    }

                    dp[i + 1][count] = take;
                    indices[i + 1][count] = current;
                }
            }
        }
        return indices[n][4];
    }
};