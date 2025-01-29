#include "ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//初版  但可以不用虚拟头节点（哑节点）因为不需要对头节点进行处理
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummyHeadA=new ListNode(0);
        dummyHeadA->next=headA;
        ListNode* dummyHeadB=new ListNode(0);
        dummyHeadB->next=headB;
        ListNode* curA=dummyHeadA;
        ListNode* curB=dummyHeadB;

        int A=0;
        int B=0;
        while(curA->next){
            A++;
            curA=curA->next;
        }
        while(curB->next){
            B++;
            curB=curB->next;
        }

        curA=dummyHeadA;
        curB=dummyHeadB;

        if(A>B){
            for(int i=0;i<A-B;i++){
                curA=curA->next;
            }
        }else{
            for(int i=0;i<B-A;i++){
                curB=curB->next;
            }
        }

        while(curA->next!=curB->next&&curA->next&&curB->next){
            curA=curA->next;
            curB=curB->next;
        }
        if(curA->next==curB->next) return curA->next;
        else return nullptr;
    }
};