#include <stdio.h>
#include <stdlib.h>
#define NOTFIND -1
typedef int Element;
typedef struct LNode* PtrToNode;
struct LNode{
    Element data;
    PtrToNode prior;
    PtrToNode next;
};
typedef PtrToNode List;

List createDoubleList(){
    List head;
    head=(PtrToNode)malloc(sizeof(struct LNode));
    head->prior=NULL;
    head->next=NULL;
    return head;
}

void Insert(List L,Element x,int index){
    PtrToNode p=L->next;
    int i=0;
    while(p&&i<index-1){
        p=p->next;
        i++;
    }
    if(p){
        PtrToNode s=(PtrToNode)malloc(sizeof(struct LNode));
        s->prior=p;
        s->next=p->next;
        p->next->prior=s;
        p->next=s;
    }else{
        printf("插入位置异常\n");
    }
}

Element Delete(List L,int index){
    PtrToNode p=L->next;
    int i=0;
    Element data=NOTFIND;
    while(p&&i<index-1){
        p=p->next;
        i++;
    }
    if(p){
        data=p->data;
        p->prior->next=p->next;
        p->next->prior=p->prior;
        free(p);
    }
    return data;
}