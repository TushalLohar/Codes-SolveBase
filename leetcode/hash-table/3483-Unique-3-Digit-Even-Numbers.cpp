class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10);

        for (int x : digits) {
            cnt[x]++;
        }

        set<int> st;

        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 9; c++) {
                    if (c % 2 != 0) continue;

                    vector<int> used(10, 0);
                    used[a]++;
                    used[b]++;
                    used[c]++;

                    bool possible = true;

                    for (int d = 0; d < 10; d++) {
                        if (used[d] > cnt[d]) {
                            possible = false;
                            break;
                        }
                    }

                    if (possible) {
                        st.insert(a * 100 + b * 10 + c);
                    }
                }
            }
        }

        return st.size();
    }
};