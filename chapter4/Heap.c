#include <stdio.h>
#include <stdlib.h>
typedef struct HNode* Heap;
typedef int ElementType;
struct HNode{
    ElementType* Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
#define MAXDATA 1000
#define ERROR -1
typedef enum{false,true} bool;

MaxHeap CreateHeap(int MaxSize);
bool IsFull(MaxHeap H);
bool Insert(MaxHeap H,ElementType X);
bool IsEmpty(MaxHeap H);
ElementType DeleteMax(MaxHeap H);

MaxHeap CreateHeap(int MaxSize){
    MaxHeap H= (MaxHeap)malloc(sizeof(struct HNode));
    H->Data =(ElementType *) malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity=MaxSize;
    H->Data[0]=MAXDATA;
    return H;
}

bool IsFull(MaxHeap H){
    return H->Size==H->Capacity;
}

bool Insert(MaxHeap H,ElementType X){
    if(IsFull(H)){
        printf("heap is full\n");
        return false;
    }
    int i=++H->Size;
    for(;H->Data[i/2]<X;i/=2){
        H->Data[i]=H->Data[i/2];
    }
    H->Data[i]=X;
    return true;
}

bool IsEmpty(MaxHeap H){
    return H->Size==0;
}

ElementType DeleteMax(MaxHeap H){
    int Parent,Child;
    ElementType MaxItem,X;
    if(IsEmpty(H)){
        printf("MaxHeap is empty!\n");
        return ERROR;
    }

    MaxItem=H->Data[1];
    X=H->Data[H->Size--];
    for(Parent=1;Parent*2<=H->Size;Parent=Child){
        Child=Parent*2;
        if((Child!=H->Size)&&(H->Data[Child]<H->Data[Child+1]))
            Child++;// 指向右儿子
        if(H->Data[Child]<=X){ // 如果该结点小于X,则结束交换父子结点
            break;
        }else{
            H->Data[Parent]=H->Data[Child]; //交换父子结点
        }
    }
    H->Data[Parent]=X; // 插入正确的位置
    return MaxItem;
}