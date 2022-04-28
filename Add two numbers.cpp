
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp;
        ListNode* head;
        head = temp = new ListNode(-1);
        if(!l1) return l2;
        if(!l2) return l1;
        int carry = 0;
        while(l1 || l2){
            int val1, val2;
            if(l1) val1 = l1->val;
            else val1 = 0;
            if(l2) val2 = l2->val;
            else val2 = 0;
            
            int total = (val1 + val2 + carry);
            int node = total % 10;
            carry = total/10;
            temp->next = new ListNode(node);
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            temp = temp->next;
        }
        if(carry) temp->next = new ListNode(carry);
        return head->next;
    }
};
