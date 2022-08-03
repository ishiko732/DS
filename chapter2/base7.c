#include <stdio.h>
#define MAXN 9

void rightShift(int L[],int left,int i){
    int j,tmp=L[i];
    for(j=i;j>left;j--){
        L[j]=L[j-1];
    }
    L[j]=tmp;
}
void leftShift(int L[],int left,int i){
    int j,tmp=L[left];
    for(j=left;j<i;j++){
        L[j]=L[j+1];
    }
    L[j]=tmp;
}

void Permutation(int L[],int left,int right){
    if(left==right){
        for(int i=0;i<=right;i++){
            printf("%d",L[i]);
        }
        printf("\n");
    }else{
        for(int i=left;i<=right;i++){
            rightShift(L,left,i);
            Permutation(L,left+1,right);
            leftShift(L,left,i);
        }
    }
}

int main(){
    int N,L[MAXN];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        L[i]=i+1;
    }
    Permutation(L,0,N-1);
    return 0;
}