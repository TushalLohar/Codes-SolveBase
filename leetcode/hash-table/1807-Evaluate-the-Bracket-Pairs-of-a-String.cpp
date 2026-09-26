class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> values;
        for (auto& pair : knowledge) {
            values[pair[0]] = pair[1];
        }
        string answer;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(') {
                answer += s[i];
                continue;
            }
            int j = i + 1;

            while (s[j] != ')') {
                j++;
            }
            string key = s.substr(i + 1, j - i - 1);
            if (values.count(key)) {
                answer += values[key];
            } else {
                answer += '?';
            }
            i = j;
        }
        return answer;
    }
};