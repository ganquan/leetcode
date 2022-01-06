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
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummyNode = new ListNode(-101);
        ListNode *merged = nullptr;
        ListNode *mergedCursor = dummyNode;
        
        ListNode *cursor1 = list1;
        ListNode *cursor2 = list2;
        
        while (cursor1 != nullptr && cursor2 != nullptr) {
            
            if (cursor1->val < cursor2->val) {
                mergedCursor->next = cursor1;
                cursor1 = cursor1->next;
            } else {
                mergedCursor->next = cursor2;
                cursor2 = cursor2->next;
            }
            
            mergedCursor = mergedCursor->next;
            
        }
        
        mergedCursor->next = cursor1 == nullptr ? cursor2 : cursor1;
        
        merged = dummyNode->next;
        delete dummyNode;
        
        return merged;
    }
};
