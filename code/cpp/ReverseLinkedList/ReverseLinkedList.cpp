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


// 数据结构基础
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if (NULL == head) {
            return NULL;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        
        while (NULL != curr) {
            next = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        
        return prev;
    }
};