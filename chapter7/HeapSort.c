#include <stdio.h>
#include <stdlib.h>

#ifndef ElementType
typedef int ElementType;
#endif
void Swap(ElementType* a,ElementType* b){
    ElementType t=*a;
    *a=*b;
    *b=t;
}
void PercDown(ElementType A[],int p,int N);
void HeapSort(ElementType A[],int N);

void PercDown(ElementType A[],int p,int N){
    int Parent,Child;
    ElementType X;
    X=A[p];
    for(Parent=p;(Parent*2+1)<N;Parent=Child){
        Child=Parent*2+1;
        if((Child!=N-1)&&(A[Child]<A[Child+1])){
            Child++;
        }
        if(X>=A[Child]) break;
        else{
            A[Parent]=A[Child];
        }
    }
    A[Parent]=X;
}

void HeapSort(ElementType A[],int N){
    int i;
    for(i=N/2-1;i>=0;i--){ // 创建最大堆
        PercDown(A,i,N);
    }
    for(i=N-1;i>0;i--){ // 删除栈顶元素
        Swap(&A[0],&A[i]); // 交换栈顶元素到末尾处
        PercDown(A,0,i);
    }
}