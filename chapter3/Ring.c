#include <stdio.h>
#include <stdlib.h>

typedef struct LNode* PtrToNode;
struct LNode{
    int id;
    PtrToNode pre;
    PtrToNode next;
};
typedef PtrToNode List;

List RingConstruct(int n){
    int i;
    List L;
    PtrToNode p,q;
    L= (List)malloc(sizeof(struct LNode));
    L->id=1;
    p=L;
    for(i=2;i<=n;i++){
        q=(PtrToNode)malloc(sizeof(struct LNode));
        q->id=i;

        p->next=q;
        q->pre=p;
        p=p->next;
    }
    L->pre=q;
    return L;
}

int boundMachine(int order){
    int boundList[4]={3,5,7,13};
    return boundList[(order-1)%4];
}

PtrToNode count(PtrToNode L,int bound){
    PtrToNode p=L;
    for(int i=2;p&&i<=bound;i++){
        p=p->next;
    }
    return p;
}

PtrToNode removeNode(PtrToNode CurrentNode){
    PtrToNode Node=CurrentNode->next;
    CurrentNode->pre->next=CurrentNode->next;
    Node->pre=CurrentNode->pre;
    printf("%d\n",CurrentNode->id);
    free(CurrentNode);
    return Node;
}

int main(){
    int n=20;
    List L = RingConstruct(n);
    PtrToNode toRemove;
    for(int i=1;i<=n;i++){
        toRemove=count(L,boundMachine(i));
        if(toRemove){
            L=removeNode(toRemove);
        }else{
            break;
        }
    }
    return 0;
}