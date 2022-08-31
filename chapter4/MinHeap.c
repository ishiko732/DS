#include <stdio.h>
#include <stdlib.h>
#ifndef ElementType
#define ElementType int
#endif
typedef struct HNode* Heap;
struct HNode{
    ElementType* Data;
    int Size;
    int Capacity;
};
typedef Heap MinHeap;
#define MAXDATA 1000
#define ERROR -1
typedef enum{false,true} bool;

MinHeap CreateHeap(int MaxSize);
bool IsFull(MinHeap H);
bool Insert(MinHeap H,ElementType X);
bool IsEmpty(MinHeap H);
ElementType DeleteMax(MinHeap H);

MinHeap CreateHeap(int MaxSize){
    MinHeap H= (MinHeap)malloc(sizeof(struct HNode));
    H->Data =(ElementType *) malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity=MaxSize;
    H->Data[0]=MAXDATA;
    return H;
}

bool IsFull(MinHeap H){
    return H->Size==H->Capacity;
}

bool Insert(MinHeap H,ElementType X){
    if(IsFull(H)){
        printf("heap is full\n");
        return false;
    }
    int i=++H->Size;
    for(;H->Data[i/2]>X;i/=2){
        H->Data[i]=H->Data[i/2];
    }
    H->Data[i]=X;
    return true;
}

bool IsEmpty(MinHeap H){
    return H->Size==0;
}

ElementType DeleteMin(MinHeap H){
    int Parent,Child;
    ElementType MinItem,X;
    if(IsEmpty(H)){
        printf("MinHeap is empty!\n");
        return ERROR;
    }

    MinItem=H->Data[1];
    X=H->Data[H->Size--];
    for(Parent=1;Parent*2<=H->Size;Parent=Child){
        Child=Parent*2;
        if((Child!=H->Size)&&(H->Data[Child]>H->Data[Child+1]))
            Child++;// 指向右儿子
        if(H->Data[Child]>=X){ // 如果该结点大于X,则结束交换父子结点
            break;
        }else{
            H->Data[Parent]=H->Data[Child]; //交换父子结点
        }
    }
    H->Data[Parent]=X; // 插入正确的位置
    return MinItem;
}

void PercDown(MinHeap H,int p){ //与删除堆类似
    int Parent,Child;
    ElementType X;

    X=H->Data[p];
    for(Parent=p;Parent*2<=H->Size;Parent=Child){
        Child=Parent*2;
        if((Child!=H->Size)&&(H->Data[Child]>H->Data[Child+1]))
            Child++;
        if(H->Data[Child]>=X){
            break;
        }else{
            H->Data[Parent]=H->Data[Child];
        }
    }
    H->Data[Parent]=X;
}

void BuildHeap(MinHeap H){
    int i;
    for(i=H->Size/2;i>0;i--){
        PercDown(H,i);
    }
}