struct ListNode {
    int val;
    ListNode* next;

    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode* next): val(val), next(next) {}
};

class Solution {
public:
    ListNode* swap_node_in_pairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* result = head->next;
        ListNode* prev = nullptr;

        while (head && head->next) {

            ListNode* next_head = head->next->next;
            ListNode* head_next = head->next;

            if (prev) {
                prev->next = head_next;
            }

            head_next->next = head;
            prev = head;
            head = next_head;
        }
        prev->next = nullptr;

        if (head) {
            prev->next = head;
        }
        
        return result;
    }
};
