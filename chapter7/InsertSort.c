#include "Sort.h"

void InsertionSort(ElementType A[],int N){
    int P,i;
    ElementType Tmp;
    for(P=1;P<N;P++){ // N-1轮
        Tmp=A[P];
        for(i=P;i>0&&A[i-1]>Tmp;i--){
            A[i]=A[i-1];
        }
        A[i]=Tmp;
    }
}

void ShellSort(ElementType A[],int N){
    int Si,D,P,i;
    ElementType Tmp;
    int Sedgewick[]={929,505,209,109,41,19,5,1,0}; // 4^i-3*2^i+1
    for(Si=0;Sedgewick[Si]>N;Si++);// 初始增量不能超过待排序的长度

    for(D=Sedgewick[Si];D>0;D=Sedgewick[++Si]){
        for(P=D;P<N;P++){
            Tmp=A[P];
            for(i=P;i>=D&&(A[i-D]>Tmp);i-=D){
                A[i]=A[i-D];
            }
            A[i]=Tmp;
        }
    }
}