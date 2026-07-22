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
    ListNode* reverseList(ListNode* head) {   // given: head
        ListNode* prev = nullptr;             // you declare these three
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;  // declared fresh each loop
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

