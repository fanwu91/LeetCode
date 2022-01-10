struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge_two_lists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* h = head;

        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    h->next = l1;
                    l1 = l1->next;
                } else {
                    h->next = l2;
                    l2 = l2->next;
                }
            } else if(l1) {
                h->next = l1;
                l1 = l1->next;
            } else {
                h->next = l2;
                l2 = l2->next;
            }
            h = h->next;
        }

        ListNode* result = head->next;
        delete head;
        head = nullptr;
        return result;
    }
};
