class Solution {
public:

    bool isValid(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }
        return balance == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }
        unordered_set<string> candidates;
        candidates.insert(s);
        for (int k = 0; k < leftRemove; k++) {
            unordered_set<string> next;
            for (string str : candidates) {
                for (int i = 0; i < str.size(); i++) {
                    if (str[i] != '(')
                        continue;
                    string temp = str;
                    temp.erase(i, 1);

                    next.insert(temp);
                }
            }
            candidates = next;
        }
        for (int k = 0; k < rightRemove; k++) {
            unordered_set<string> next;
            for (string str : candidates) {
                for (int i = 0; i < str.size(); i++) {
                    if (str[i] != ')')
                        continue;

                    string temp = str;
                    temp.erase(i, 1);

                    next.insert(temp);
                }
            }
            candidates = next;
        }
        vector<string> answer;
        for (string str : candidates) {
            if (isValid(str))
                answer.push_back(str);
        }
        return answer;
    }
};