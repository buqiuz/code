/*
* 一般情况都是对cur_next进行操作，这样我们就可以同时拥有cur和cur->next的信息。也就是说不会丢失前一个节点信息。
* 对于头节点，进行操作时通常需要额外处理，所以可以引入一个dummyHead节点，这样就可以统一处理。
* 这样cur就是dummyHead，cur->next就是head，这样就可以统一处理了。
*/


//初版
#include "ListNode.h"

class MyLinkedList {
public:
    MyLinkedList() {
        _dummyHead =new LinkedNode(0);
        _size =0;
    }
    
    int get(int index) {
        if(index>=_size||index<0)
        return -1;

        LinkedNode* cur=_dummyHead;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        return cur->next->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* node=new LinkedNode(val);
        node->next=_dummyHead->next;
        _dummyHead->next=node;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* cur=_dummyHead;
        while(cur->next){
            cur=cur->next;
        }
        LinkedNode* node = new LinkedNode(val);
        cur->next=node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>_size||index<0)
        return;

        LinkedNode* cur=_dummyHead;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        LinkedNode* node =new LinkedNode(val);
        node->next=cur->next;
        cur->next=node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=_size||index<0)
        return;

        LinkedNode* cur=_dummyHead;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        LinkedNode* temp =cur->next;
        cur->next=cur->next->next;
        delete temp;
        _size--;
    }
private:
    LinkedNode* _dummyHead;
    int _size;
};


//版本一 利用尾指针维护链表尾部，方便添加尾部元素
struct LinkedNode{
    int val;
    LinkedNode* next;
    LinkedNode(int val):val(val),next(nullptr){}
};

class MyLinkedList {
public:

    MyLinkedList() {
        _dummyHead =new LinkedNode(0);
        _tail =_dummyHead;
        _size =0;
    }
    
    int get(int index) {
        if(index>=_size||index<0)
        return -1;

        LinkedNode* cur=_dummyHead;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        return cur->next->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* node=new LinkedNode(val);
        node->next=_dummyHead->next;
        _dummyHead->next=node;

        if(_size==0)
            _tail=node;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* node = new LinkedNode(val);
        _tail->next=node;
        _tail=node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>_size||index<0)
        return;

        LinkedNode* cur=_dummyHead;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        LinkedNode* node =new LinkedNode(val);
        node->next=cur->next;
        cur->next=node;

        if(index==_size)
            _tail=node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=_size||index<0)
            return;

        LinkedNode* cur=_dummyHead;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        LinkedNode* temp =cur->next;
        cur->next=cur->next->next;

        if(temp==_tail)
            _tail=cur;

        delete temp;
        _size--;
    }
private:
    LinkedNode* _dummyHead;
    LinkedNode* _tail;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */