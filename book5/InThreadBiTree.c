#include <stdio.h>
#include <stdlib.h>
#define NoInfo '#'
typedef char Element;
typedef struct ThrNode* PtrToNode;
struct ThrNode{
    Element Data;
    PtrToNode Left;
    PtrToNode Right;
    int LeftTag;
    int RightTag;
};
typedef PtrToNode InThreadBTree;
typedef InThreadBTree TreeType;
#define MAXSIZE 100
#include "../chapter4/Queue_op.c"

InThreadBTree CreatBinTree()
{
    Element Data;
    InThreadBTree BT, T;
    Queue Q = CreateQueue(MAXSIZE);
    scanf("%c", &Data);
    if (Data != NoInfo)
    {
        BT = (InThreadBTree)malloc(sizeof(struct ThrNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        BT->LeftTag=BT->RightTag=0;
        AddQ(Q, BT);
    }else
    {
        return NULL;
    }
    while (!isEmpty(Q))
    {
        T = DeleteQ(Q);
        scanf("%c", &Data);
        if (Data == NoInfo || Data == '\n')
            T->Left = NULL;
        else
        {
            T->Left = (InThreadBTree)malloc(sizeof(struct ThrNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            T->LeftTag=T->RightTag=0;
            AddQ(Q, T->Left);
        }
        scanf("%c", &Data);
        if (Data == NoInfo || Data == '\n')
            T->Right = NULL;
        else
        {
            T->Right = (InThreadBTree)malloc(sizeof(struct ThrNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            T->LeftTag=T->RightTag=0;
            AddQ(Q, T->Right);
        }
    }
    return BT;
}
void createInThreadBTree(InThreadBTree node,PtrToNode pre){
    if(!node){
        return ;
    }
    createInThreadBTree(node->Left,pre);
    if(!node->Left){
        node->Left=pre;
        node->LeftTag=1;
    }
    if(pre&&!pre->Right){//当pre不为空,且pre的右孩子为空时,变更右孩子为父结点
        pre->Right=node;
        pre->RightTag=1;
    }
    pre=node;//移动指针
    createInThreadBTree(node->Right,pre);

}

InThreadBTree initThreadBTree(){
    InThreadBTree root=CreatBinTree();
    PtrToNode pre=NULL;
    if(root){
        createInThreadBTree(root,pre);
        pre->RightTag=1;//中序线索树的最后一个叶子结点右孩子结点一定指向根结点
    }
}

PtrToNode first(PtrToNode node){
    PtrToNode p=node;
    while(p->LeftTag==0){
        p=p->Left;
    }
    return p;
}

PtrToNode next(PtrToNode node){
    PtrToNode p=node->Right;
    if(p->RightTag==1){
        return p;
    }else{
        return first(p);
    }
}

void inOrder(InThreadBTree root){
    PtrToNode p=first(root);
    while(p){
        printf("%d ",p->Data);
        p=next(p);
    }
    return ;
}