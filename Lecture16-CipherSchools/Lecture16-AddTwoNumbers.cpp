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

ListNode *addTwoNumbers(ListNode *a, ListNode *b) {
    if(a==NULL) return b;
    else if(b==NULL) return a;
    else {
        ListNode dummy(0);
        ListNode *p=a, *q=b, *r = &dummy;
        int sum=0, carry=0;
        while(p!=NULL || q!=NULL) {
            sum=(p==NULL?0:p->val) + (q==NULL?0:q->val) + carry;
            carry=sum/10;
            sum=sum%10;
            r->next=new ListNode(sum);
            r=r->next;
            if(p!=NULL) p=p->next;
            if(q!=NULL) q=q->next;
        }
        if(carry>0) {
            r->next=new ListNode(carry);
        }
        return dummy.next;
    }
}
int main() {
    
}