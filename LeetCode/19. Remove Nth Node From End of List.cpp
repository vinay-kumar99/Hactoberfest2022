class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* A, int k) {
    ListNode* p = A;
    ListNode* q = A;
    int c = 0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    if(k >= c){
        return A->next;
    }
    if(c==1){
        return NULL;
    }
    for(int i = 0; i<c-k-1; i++){
        
        q = q->next;
    }
    q->next = q->next->next;
    return A;    
    }
};
