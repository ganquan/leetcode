
#include <vector>
#include <map>
#include <utility>
#include <queue>

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

    // leetcode OJ性能不稳定，一样的代码，多次submit，最快如下。最慢52ms。。。
    // 不纠结了
    // Runtime: 12 ms, faster than 99.78% of C++ online submissions for Merge k Sorted Lists.
    // Memory Usage: 13.9 MB, less than 27.47% of C++ online submissions for Merge k Sorted Lists.
    //
    // 利用题目中的有序信息，一定程度上可以减少merge过程无意义的对比
    // 如果链表长度相同，元素也完全相同，也就是说lists中全部都是一样的list，且都很长
    // 这个算法存在劣化
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.size() == 0) {
            return nullptr;
        }
        
        queue<ListNode*> q;
        int i = 0, j = 0, step = 2;
        
        for(i = 0, j = i + 1; j < lists.size(); i += step, j = i + 1) {
            q.push(mergeTwoLists(lists[i], lists[j]));
        }
        
        //奇数长度，存在未能配对落单的链表
        if (j == lists.size()) {
            q.push(lists[j-1]);
        }
        
        
        while (q.size() > 1) {
            
            ListNode *first = q.front();
            q.pop();
            ListNode *second = q.front();
            q.pop();
            
            q.push(mergeTwoLists(first, second));
        }

        return q.front();
    }

    //其实这个是完全放弃了题目中每个List都是有序的这个条件，适用于merge无序的链表
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