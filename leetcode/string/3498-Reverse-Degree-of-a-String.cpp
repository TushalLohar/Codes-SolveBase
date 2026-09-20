class Solution {
public:
    int reverseDegree(string s) {
        int answer = 0;
        for (int i = 0; i < s.size(); i++) {
            int reverseValue = 26 - (s[i] - 'a');
            answer += reverseValue * (i + 1);
        }
        return answer;
    }
};