/*
   1. reverse the list
   2. delete nth node from begining
   3. reverse the list
*/
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp = NULL;
        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        if(n==1){
            head = head->next;
            return reverse(head);
        }
        ListNode* temp = head;
        for(int i=1; i<n-1; i++) temp = temp->next;
        temp->next = temp->next->next;
        return reverse(head);
    }
};
