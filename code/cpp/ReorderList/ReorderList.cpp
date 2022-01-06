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
    
    //Runtime: 74 ms, faster than 11.56% of C++ online submissions for Reorder List.
    //Memory Usage: 18.2 MB, less than 42.89% of C++ online submissions for Reorder List.
    void reorderList(ListNode* head) {
        
        int const MAX_NODE_COUNT = 5 * 10000;
        ListNode *arr[MAX_NODE_COUNT] = {};
        int len = 0;
        ListNode *dummyhead = new ListNode(-1);
        ListNode *cursor = dummyhead;
        
        ListNode *curr = head;
        while (curr != nullptr) {
            arr[len] = curr;
            curr = curr->next;
            len++;
        }
        
        //reorder
        for(int start = 0, end = len - 1; start <= end; start++, end--) {
            if (start != end) {
                cursor->next = arr[start];
                cursor->next->next = arr[end];
                
                cursor = cursor->next->next;
            } else {
                //奇数个node，还剩中间1个
                cursor->next = arr[start];
                cursor = cursor->next;
            }
            
            //断开旧链接
            cursor->next = nullptr;
        }
        
        head = dummyhead->next;
        delete dummyhead;
    }
};
