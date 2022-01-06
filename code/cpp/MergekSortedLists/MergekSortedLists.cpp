
#include <vector>
#include <map>
#include <utility>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //Runtime: 32 ms, faster than 40.75% of C++ online submissions for Merge k Sorted Lists.
    //Memory Usage: 13.6 MB, less than 37.63% of C++ online submissions for Merge k Sorted Lists.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *dummyNode = new ListNode(-10001);
        ListNode *merged = nullptr;
        ListNode *mergeCursor = dummyNode;
        
        //pair first保存该key对应val的节点组成的链表的head
        //pair second保存该key对应val的节点组成的链表的tail
        map<int, pair<ListNode*, ListNode*>> m = {};
        
        unsigned long list_len= lists.size();
        
        //把全部node整理到m中
        for(int i = 0; i < list_len; i++) {
            
            ListNode* cursor = lists[i];
            
            while (cursor != nullptr) {
                
                ListNode *next = cursor->next;
                
                if (m.find(cursor->val) == m.end()) {
                    //还没有存放过
                    m[cursor->val] = make_pair(cursor, cursor);
                    
                    //断开之前的连接
                    cursor->next = nullptr;
                } else {
                    //已存放的node往后移，成为新存入node的next
                    cursor->next = m[cursor->val].first;
                    m[cursor->val].first = cursor;
                }
                
                cursor = next;
            }
        }
        
        //连接起来
        for(map<int, pair<ListNode*, ListNode*>>::iterator iter = m.begin(); iter != m.end(); ++iter) {
            
            //连接head
            mergeCursor->next = (*iter).second.first;
            //直接去到tail
            mergeCursor = (*iter).second.second;
            
        }
        
        merged = dummyNode->next;
        
        delete dummyNode;
        
        return merged;
    }
    
};