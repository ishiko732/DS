#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef enum{false,true} bool;
typedef int Position;
typedef int ElementType;
typedef struct SNode* PtrToSNode;
struct SNode{
    ElementType* Data;
    Position Top1;
    Position Top2;
    int MaxSize;
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize){
    Stack s=(Stack)malloc(sizeof(struct SNode));
    s->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
    s->MaxSize=MaxSize;
    s->Top1=-1;
    s->Top2=MaxSize;
    return s;
}
bool Push(Stack S,ElementType X,int Tag){
    if(S->Top2-S->Top1==1){
        printf("Stack Full\n");
        return false;
    }else{
        if(Tag==1){
            S->Data[++S->Top1]=X;
        }else{
            S->Data[--S->Top2]=X;
        }
        return true;
    }
}

ElementType Pop(Stack S,int Tag){
    if(Tag==1){
        if(S->Top1==-1){
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }else{
            return S->Data[S->Top1--];
        }
    }else{
        if(S->Top2==S->MaxSize){
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }else{
            return S->Data[S->Top2++];
        }
    }
}