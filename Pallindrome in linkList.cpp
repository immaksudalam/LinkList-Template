/*
   1. Reach middle of linkList and return the middle as new linkList
   2. Reverse the new list and capare it value by value.
*/

class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp = NULL;
        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur= temp;
        }
        return prev;
    }
    bool compare(ListNode* l1, ListNode* l2){
        if(!l1 || !l2) return true;
        return (l1->val == l2->val) && compare(l1->next, l2->next);
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* mid = findMid(head);
        ListNode* l2 = mid->next;
        mid->next = NULL;
        l2 = reverse(l2);
        return compare(head, l2);
    }
};
