#include <stdio.h>

typedef int ElementType;
void Swap(ElementType *x,ElementType *y){
    ElementType tmp=*x;
    *x=*y;
    *y=tmp;
}

ElementType FindKthLargest(ElementType S[],int K,int left,int right){
    ElementType e=S[left];
    int L=left,R=right;

    while(1){
        while(left<=right&&e<=S[left]) left++;
        while(left<=right&&e>S[left]) right--;
        if(left<right){
            Swap(&S[left],&S[right]);
        }else{
            break;
        }
    }
    Swap(&S[left-1],&S[L]);
    if((left-L-1)>=K){
        return FindKthLargest(S,K,L,left-2);
    }else if((left-L-1)<K-1){
        return FindKthLargest(S,K-(left-L-1),left,R);
    }else{
        return e;
    }
}

ElementType Median(ElementType S[],int N){
    return FindKthLargest(S,(N+1)/2,0,N-1);
}

int main(){

}

