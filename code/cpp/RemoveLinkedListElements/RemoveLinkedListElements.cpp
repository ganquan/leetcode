//
//  main.cpp
//  testcpp
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
    
    //Runtime: 16 ms, faster than 96.36% of C++ online submissions for Remove Linked List Elements.
    //Memory Usage: 15.2 MB, less than 25.54% of C++ online submissions for Remove Linked List Elements.
    ListNode* removeElements(ListNode* head, int val) {
        
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *curr = head;
        ListNode *prev = nullptr;
        
        while (curr != nullptr) {
            
            if (curr->val == val) {
                
                if (curr == head) {
                    head = head->next;
                    delete curr;
                    curr = head;
                } else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
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
    int src5[] = {5,2,3,4,5};
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
    
    
    //7
    int src7[] = {1,3,4,7,1,2,6};
    vector<int> dest7;
    dest7.assign(std::begin(src7), std::end(src7));
    
    ListNode *head7 = initListFromArray(dest7);
    printList(head7);
    
    
    //8
    int src8[] = {8,8,4,7,1,2,8,8};
    vector<int> dest8;
    dest8.assign(std::begin(src8), std::end(src8));
    
    ListNode *head8 = initListFromArray(dest8);
    printList(head8);
    
    //9
    int src9[] = {9,9,9};
    vector<int> dest9;
    dest9.assign(std::begin(src9), std::end(src9));
    
    ListNode *head9 = initListFromArray(dest9);
    printList(head9);
    
    
    cout << "===============" << endl;
    Solution s = Solution();
    printList(s.removeElements(head1, 1));
    printList(s.removeElements(head2, 2));
    printList(s.removeElements(head3, 3));
    printList(s.removeElements(head4, 4));
    printList(s.removeElements(head5, 5));
    printList(s.removeElements(head6, 6));
    printList(s.removeElements(head7, 7));
    printList(s.removeElements(head8, 8));
    printList(s.removeElements(head9, 9));
    
    return 0;
}
