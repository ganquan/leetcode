//
//  main.cpp
//  leetcode
//
//  Created by Quan Gan on 2022/1/1.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* initListFromArray(vector<int> v) {
    if (v.size() == 0) {
        return nullptr;
    }
    
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    
    for (int i = 0; i < v.size(); i++) {
        
        ListNode* temp = new ListNode(v[i]);
        
        if (head == nullptr) {
            head = temp;
            curr = head;
        } else {
            curr->next = temp;
            curr = temp;
        }
    }
    
    return head;
};

void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "[]" << endl;
        return ;
    }
    
    ListNode *curr = head;
    cout << "[";
    
    do {
        cout << curr->val;
        if (curr->next != nullptr) {
            cout << ",";
        }
        
        curr = curr->next;
        
    } while (curr != nullptr);
    
    cout << "]" << endl;
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        if (head == nullptr) {
            //参数为空
            return nullptr;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if (fast->next != nullptr && slow != fast->next) {
            slow = slow->next;
        }
        
        return slow;
    }
};


int main(int argc, const char * argv[]) {
    
    //1
    int src1[] = {1};
    vector<int> dest1;
    dest1.assign(std::begin(src1), std::end(src1));
    
    ListNode *head1 = initListFromArray(dest1);
    printList(head1);
    
    //2
    int src2[] = {1,2};
    vector<int> dest2;
    dest2.assign(std::begin(src2), std::end(src2));
    
    ListNode *head2 = initListFromArray(dest2);
    printList(head2);
    
    //3
    int src3[] = {1,2,3};
    vector<int> dest3;
    dest3.assign(std::begin(src3), std::end(src3));
    
    ListNode *head3 = initListFromArray(dest3);
    printList(head3);
    
    //4
    int src4[] = {1,2,3,4};
    vector<int> dest4;
    dest4.assign(std::begin(src4), std::end(src4));
    
    ListNode *head4 = initListFromArray(dest4);
    printList(head4);
    
    //5
    int src5[] = {1,2,3,4,5};
    vector<int> dest5;
    dest5.assign(std::begin(src5), std::end(src5));
    
    ListNode *head5 = initListFromArray(dest5);
    printList(head5);
    
    
    //6
    int src6[] = {1,2,3,4,5,6};
    vector<int> dest6;
    dest6.assign(std::begin(src6), std::end(src6));
    
    ListNode *head6 = initListFromArray(dest6);
    printList(head6);
    

    
    cout << "===============" << endl;
    Solution s = Solution();
    printList(s.middleNode(head1));
    printList(s.middleNode(head2));
    printList(s.middleNode(head3));
    printList(s.middleNode(head4));
    printList(s.middleNode(head5));
    printList(s.middleNode(head6));
    
    return 0;
}
