/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if (NULL == head) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            if (fast == slow) {
                return true;
            }
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};