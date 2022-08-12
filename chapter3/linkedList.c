# include <stdio.h>
# include <stdlib.h>
#define ERROR -1
typedef enum bool{false,true} bool;
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

int Length(List L){
    Position p;
    int cnt=0;
    p=L;
    while(p){
        p=p->Next;
        cnt++;
    }
    return cnt;
}

ElementType FindKth(List L,int K){
    Position p=L;
    int cnt=1; // 位序从1开始
    while(p&&cnt<K){
        p=p->Next;
        cnt++;
    }
    if(cnt==K&&p){
        return p->Data;
    }else{
        return ERROR;
    }
}

Position Find(List L,ElementType X){
    Position p=L;
    while(p&&p->Data!=X){
        p=p->Next;
    }
    return p;
}

Position _FindPre(List L,int index){
    Position p=L;
    int cnt=0;
    while(p&&cnt<index-1){
        p=p->Next;
        cnt++;
    }
    if(p==NULL || cnt!=index-1){
        return NULL;
    }else{
        return p;
    }
} 

List Insert(List L,ElementType X,int i){
    Position tmp,pre;
    tmp = (Position) malloc(sizeof(struct LNode));
    tmp ->Data =X;
    tmp ->Next =NULL;

    if(i==1){ // 头插入(位序)
        tmp ->Next=L;
        return tmp;
    }else{
        pre=_FindPre(L,i);
        if(pre==NULL){
            printf("插入错误\n");
            free(tmp);
            return NULL;
        }else{
            tmp->Next=pre->Next;
            pre->Next=tmp;
            return L;
        }
    }
}

List Delete( List L, int i ){
    Position p,tmp;
    if(i==1){
        p=L;
        tmp = p;
        p=p->Next;
        free(tmp);
        return p;
    }else{
        p=_FindPre(L,i);
        if(p==NULL){
            printf("删除错误\n");
            return L;
        }else{
            tmp = p->Next;
            p->Next=tmp->Next;
            free(tmp);
            return L;
        }
    }
}