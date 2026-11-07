class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<pair<int, int>> avail;
        set<tuple<long long, int, int>> busy;
        int n = servers.size();
        int m = tasks.size();
        for (int i = 0; i < n; i++) {
            avail.insert({servers[i], i});
        }
        vector<int> ans(m);
        long long time = 0;
        for (int i = 0; i < m; i++) {
            time = max(time, (long long)i);
            while (!busy.empty() && get<0>(*busy.begin()) <= time) {
                auto [t, w, id] = *busy.begin();
                busy.erase(busy.begin());
                avail.insert({w, id});
            }
            if (avail.empty()) {
                time = get<0>(*busy.begin());

                while (!busy.empty() && get<0>(*busy.begin()) <= time) {
                    auto [t, w, id] = *busy.begin();
                    busy.erase(busy.begin());
                    avail.insert({w, id});
                }
            }
            auto [w, id] = *avail.begin();
            avail.erase(avail.begin());
            ans[i] = id;
            busy.insert({time + tasks[i], w, id});
        }
        return ans;
    }
};