class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        int minDist = INT_MAX;
        int first = -1;
        int last = -1;
        int pos = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {
            if ((curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val)) {

                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (first != -1 && first != last) {
            ans[0] = minDist;
            ans[1] = last - first;
        }

        return ans;
    }
};