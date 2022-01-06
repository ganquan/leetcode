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
    
    ListNode* min(ListNode *node1, ListNode *node2) {
        if (node1->val >= node2->val) {
            return node2;
        } else {
            return node1;
        }
    }
    
    //Runtime: 4 ms, faster than 94.43% of C++ online submissions for Merge Two Sorted Lists.
    //Memory Usage: 14.9 MB, less than 46.53% of C++ online submissions for Merge Two Sorted Lists.
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *dummyNode = new ListNode(-101);
        ListNode *mergedCursor = dummyNode;
        
        ListNode *cursor1 = list1;
        ListNode *cursor2 = list2;
        
        while (cursor1 != nullptr && cursor2 != nullptr) {
            
            mergedCursor->next = min(cursor1, cursor2);
            
            if (mergedCursor->next == cursor1) {
                cursor1 = cursor1->next;
            } else {
                cursor2 = cursor2->next;
            }

            //break the old link
            mergedCursor->next->next = nullptr;
            
            mergedCursor = mergedCursor->next;
        }
        
        if (cursor1 == nullptr && cursor2 != nullptr) {
            mergedCursor->next = cursor2;
        } else if (cursor1 != nullptr && cursor2 == nullptr) {
            mergedCursor->next = cursor1;
        }
        
        return dummyNode->next;
    }  
};
