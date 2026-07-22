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
        ListNode dummy;              // a placeholder node before the real start
        ListNode* tail = &dummy;     // tail always points at the last node so far

        // While BOTH lists still have nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;       // attach list1's node
                list1 = list1->next;      // advance list1
            } else {
                tail->next = list2;       // attach list2's node
                list2 = list2->next;      // advance list2
            }
            tail = tail->next;            // move tail to the newly attached node
        }

        // One list is empty; attach whatever remains of the other
        if (list1 != nullptr) tail->next = list1;
        else                  tail->next = list2;

        return dummy.next;   // the real head is right after the dummy
    }
};

