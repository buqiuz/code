#include "ListNode.h"

//迭代  快慢指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead =new ListNode(0,head);
        ListNode* fast= dummyHead;
        ListNode* slow= dummyHead;
        while(n--){
            fast=fast->next;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp =slow->next;
        slow->next=slow->next->next;
        delete temp;
        head=dummyHead->next;
        delete dummyHead;
        return head;
    }
};

//递归
class Solution {
public:
    int cur = 0; // 用于记录节点深度的全局变量

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr; // 递归到底，返回空
        head->next = removeNthFromEnd(head->next, n); // 递归处理后续链表
        cur++; // 从尾部返回时，递增计数
        if (cur == n) { // 如果当前节点是倒数第 n 个节点
            return head->next; // 删除当前节点，返回下一节点
        }
        return head; // 否则保持当前节点不变
    }
};
