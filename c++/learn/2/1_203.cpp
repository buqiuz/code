/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 //初版

class Solution {
public:

    void deleteNode(ListNode* pre){
        ListNode* temp = pre->next;
        pre->next =pre->next->next;
        delete temp;  //避免内存泄漏
    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = new ListNode(0,head);
        ListNode* cur = new_head;

        while(cur->next!=nullptr){
            if(cur->next->val==val){
                deleteNode(cur);
            }else{
                cur =cur->next;
            }
        }

        head =new_head->next;
        delete new_head;   //避免内存泄漏
        return head;
    }
};


//版本一
class Solution {
public:

    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = new ListNode(0,head);
        ListNode* cur = new_head;

        while(cur->next!=nullptr){
            if(cur->next->val==val){
                ListNode* temp =cur->next;
                cur->next=cur->next->next;
                delete temp;
            }else{
                cur =cur->next;
            }
        }
        head = new_head->next;
        delete new_head;
        return head;
    }
};