struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *dummyHead = new ListNode(-1024, head);
        ListNode *curr = head;
        ListNode *prev = dummyHead;
        ListNode *next = curr->next;

        int step = 0;

        while (curr != nullptr) {
            if (next != nullptr && curr != nullptr && step == 0) {
                ListNode *tmp = next->next;
                ListNode *tmp_curr, *tmp_next;

                // swap
                tmp_curr = next;
                tmp_next = curr;

                tmp_curr->next = tmp_next;
                tmp_next->next = tmp;

                prev->next = tmp_curr;
                curr = tmp_curr;
                next = tmp_next;
            }

            //move forward
            prev = curr;
            curr = curr->next;
            if (curr != nullptr) {
                next = curr->next;
            }

            //count steps
            step++;
            if (step == 2) {
                step = 0;
            }
        }

        return dummyHead->next;
    }
};