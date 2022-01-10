#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct cmp {
    bool operator()(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* merge_k_lists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        // min-heap
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* dummy = new ListNode();
        ListNode* d = dummy;

        for (const auto& list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        while (!pq.empty()) {
            ListNode* top = pq.top();
            d->next = top;
            pq.pop();
            if(top->next) {
                pq.push(top->next);
            }
            d = d->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        dummy = nullptr;

        return result;
    }
};
