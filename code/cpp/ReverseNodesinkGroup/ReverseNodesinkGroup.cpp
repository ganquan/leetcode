struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            if (!cur)
                return head;
            cur = cur->next;
        }
        ListNode* curNode = reverseList(head, cur);
        head->next = reverseKGroup(cur, k);
        return curNode;
    }

    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode* pre = tail;
        while (head != tail) {
            ListNode* t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
};