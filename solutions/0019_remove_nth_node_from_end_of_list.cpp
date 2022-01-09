struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(-1), next(nullptr) {}
    ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode* next) : val(value), next(next) {}
};

class Solution {
public:
    ListNode* remove_nth_from_end(ListNode* head, int n) {
        ListNode* fast = head;
        int i = 0;
        while (i++ < n) {
            fast = fast->next;
        }

        ListNode* slow = head;
        ListNode* phead = new ListNode(-1, head);
        ListNode* p = phead;

        while (fast) {
            slow = slow->next;
            p = p->next;
            fast = fast->next;
        }

        if (slow == head) {
            ListNode* result = head->next;
            delete p;
            p = nullptr;
            delete head;
            head = nullptr;

            return result;
        }

        p->next = slow->next;
        delete slow;
        slow = nullptr;
        delete phead;
        phead = nullptr;

        return head;
    }
};