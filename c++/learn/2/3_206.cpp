#include "ListNode.h"

/*
* 之所以不能用一个指针来完成，是因为我们需要保存cur的下一个节点，以便我们可以将cur的next指向pre，然后更新pre和cur指针。
* 如果我们只有一个指针，那么在我们改变cur->next之后，我们将失去对cur后面的节点的引用。    
*/

// 初版   
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

//版本一
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;

        ListNode* newHead =reverseList(head->next);

        head->next->next=head;
        head->next=nullptr;
        
        return newHead;
    }
};

// 版本二
class Solution {
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur==nullptr) return pre;
        ListNode* temp =cur->next;
        cur->next =pre;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr,head);
    }
};