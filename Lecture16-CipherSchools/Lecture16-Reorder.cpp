#include<iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(): val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reorder(ListNode *head, int K) {
    if(head==NULL || head->next==NULL) return head;
    ListNode *p=head, *q=NULL;
    int k=0;
    while(p!=NULL && k<K) {
        k++;
        p=p->next;
    }
    if(p==NULL) return head;
    q=head;
    while(p->next!=NULL && q!=NULL) {
        p=p->next;
        q=q->next;
    }
    p->next=head;
    head=q->next;
    q->next=NULL;
    return head;
}
int main() {
    
}