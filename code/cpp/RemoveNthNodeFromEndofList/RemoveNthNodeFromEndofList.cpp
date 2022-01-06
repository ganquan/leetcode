/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    
    //Runtime: 15 ms, faster than 5.10% of C++ online submissions for Remove Nth Node From End of List.
    //Memory Usage: 10.8 MB, less than 31.66% of C++ online submissions for Remove Nth Node From End of List.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr;
        int deleyStep = n;
        
        while (deleyStep > 0 && fast != nullptr) {
            prev = fast;
            fast = fast->next;
            deleyStep -= 1;
        }
        
        while (fast != nullptr) {
            fast = fast->next;
            
            prev = slow;
            slow = slow->next;
        }
        
        //delete the slow, it's the Nth node from the end of the list
        if (slow == head) {
            head = head->next;
            slow = head;
        } else {
            //delete the slow node and make new link to the next one
            if (prev != nullptr) {
                prev->next = slow->next;
                slow = prev->next;
            }
        }
        
        return head;
    }
};