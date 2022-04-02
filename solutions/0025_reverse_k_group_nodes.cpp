struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(0), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int n = 0;
        
        ListNode* h = head;
        
        while (h) {
            ++n;
            h = h->next;
        }

        // if less than k nodes, directly return
        if (n < k) {
            return head;
        }

        // recursively append
        ListNode* prev = head;
        ListNode* hh = head;

        int m = 0;
        while (m++ < k - 1) {
            hh = hh->next;
        }
        ListNode* nextH = hh->next;
        hh->next = nullptr;

        ListNode* result = reverse(head);
        prev->next = reverseKGroup(nextH, k);
        
        return result;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* curt = nullptr;

        while (head) {
            ListNode* tmp = head->next;
            head->next = curt;
            curt = head;
            head = tmp;
        }

        return curt;
    }
};
