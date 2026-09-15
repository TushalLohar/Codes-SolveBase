class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<pair<int, int>> palindromes;

        // Odd length palindromes
        for (int center = 0; center < n; center++) {
            int left = center;
            int right = center;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= k) {
                    palindromes.push_back({left, right});
                }

                left--;
                right++;
            }
        }

        // Even length palindromes
        for (int center = 0; center + 1 < n; center++) {
            int left = center;
            int right = center + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= k) {
                    palindromes.push_back({left, right});
                }

                left--;
                right++;
            }
        }

        // Sort by ending position
        sort(palindromes.begin(), palindromes.end(),
             [](auto& a, auto& b) {
                 if (a.second != b.second)
                     return a.second < b.second;

                 return a.first > b.first;
             });

        int answer = 0;
        int lastEnd = -1;

        for (auto& palindrome : palindromes) {
            int start = palindrome.first;
            int end = palindrome.second;

            if (start > lastEnd) {
                answer++;
                lastEnd = end;
            }
        }

        return answer;
    }
};