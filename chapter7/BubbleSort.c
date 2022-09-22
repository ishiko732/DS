#include <stdio.h>
#include <stdlib.h>

#ifndef ElementType
typedef int ElementType;
#endif
#ifndef bool
typedef enum{false,true} bool;
#endif
void Swap(ElementType* a,ElementType* b){
    ElementType t=*a;
    *a=*b;
    *b=t;
}

void BubbleSort(ElementType A[],int N){
    int P,i;
    bool flag;
    for(P=N-1;P>=0;P--){
        flag=false;
        for(i=0;i<P;i++){
            if(A[i]>A[i+1]){
                Swap(&A[i],&A[i+1]);
                flag=true;
            }
        }
        if(flag==false) break;
    }
}