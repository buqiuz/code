#include "ListNode.h"
//初版
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        //先让fast指针能走
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) break;
        }

        if (!fast || !fast->next) { // 没有环
            return nullptr;
        }
        slow = head; // 重新起点

        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;

    }
};
