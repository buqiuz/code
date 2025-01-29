#include "ListNode.h"


//先处理两个节点，然后递归处理后面的节点
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 如果链表为空或只有一个节点，无需交换，直接返回
        if (!head || !head->next) {
            return head;
        }

        //定住next和后面的链表
        ListNode* next=head->next;
        ListNode* nextPair =next->next;

        //交换
        next->next=head;
        head->next=swapPairs(nextPair);
        return next;
    }
};

//接收处理好的链表，然后处理当前两个节点

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;

        ListNode* next=head->next;
        head->next=swapPairs(next->next);
        next->next=head;
        return next;
    }
};