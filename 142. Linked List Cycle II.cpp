class Solution {
public:
    ListNode* solve(ListNode* head){
        //Checking if there is a cycle using slow and fast pointer method
        ListNode* slow=head;
        ListNode* fast = head;
        bool flag = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            //Cycle detected
            if(slow == fast){
                 //Using the Floyd's cycle detection method
                fast = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
        
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* node = solve(head);
        return node;
    }
};
