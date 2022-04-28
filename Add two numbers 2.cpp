/*
    1. problem solving approach as like add two numbers 1.
    2. points the node;
    3. reverse both link list.
    4. add them.
    5. reverse the result;

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
            cur =  temp;
        }
        return prev;
    }
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2){
        l1 = reverse(l1);
        l2 = reverse(l2);
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode*head;
        ListNode* temp;
        head = temp = new ListNode(-1);
        int carry = 0;
        while(l1 || l2){
            int firstval = l1?l1->val : 0;
            int secondval = l2? l2->val:0;
            int total = (firstval + secondval + carry);
            int node = total%10;
            carry = total/10;
            temp->next = new ListNode(node);
            temp = temp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) temp->next = new ListNode(carry);
        return head->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* ans = addTwoNumber(l1, l2);
       return reverse(ans);
    }
};
