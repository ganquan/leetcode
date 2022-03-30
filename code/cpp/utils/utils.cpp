#include <iostream>
#include <vector>

using namespace std;

namespace utils {
ListNode* listFromVector(std::vector<int> v) {
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
}

vector<int> vectorFromList(ListNode* head) {
    vector<int> result;
    if (head == nullptr) {
        return result;
    }

    ListNode* curr = head;
    while (curr != nullptr) {
        result.push_back(curr->val);
        curr = curr->next;
    }

    return result;
}

void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "[]" << endl;
        return;
    }

    ListNode* curr = head;
    cout << "[";

    do {
        cout << curr->val;
        if (curr->next != nullptr) {
            cout << ",";
        }

        curr = curr->next;

    } while (curr != nullptr);

    cout << "]" << endl;
}

}  // namespace utils
