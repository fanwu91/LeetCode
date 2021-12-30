struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    ListNode* add_two_numbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(-1);
        ListNode* h = l;
        
        int carry = 0;

        while (l1 || l2 || carry) {
            int total = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            h->next = new ListNode(total % 10);
            h = h->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            carry = total / 10;
        }

        ListNode* ans = l->next;
        delete l;
        l = nullptr;
        return ans;
    }
};
