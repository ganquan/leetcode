struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
    ListNode *swapNodes(ListNode *head, int k) {
        
        ListNode * dummy = new ListNode(-1024, head);
        ListNode *front = dummy, *end = head, *cursor = head;
        int delay_step = k;

        // front: the k-th node from list beginning
        while (cursor != nullptr && front != nullptr && delay_step > 0) {
            front = front->next;
            cursor = cursor->next;
            delay_step--;
        }

        //now "end" is the the k-th node from list end
        while (cursor != nullptr) {
            end = end->next;
            cursor = cursor->next;
        }

        //swap value
        int tmp = front->val;
        front->val = end->val;
        end->val = tmp;

        return dummy->next;
    }
};
