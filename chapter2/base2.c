#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
void Shift(int Array[],int N);
int gcd(int a,int b);
int main(){
    int Number[MAXN],N,M;
    scanf("%d %d",&N,&M);
    // OP1
    // M%=N;
    // for(int i=0;i<N;i++){
    //      scanf("%d",&Number[i]);
    // }
    // for(int i=0;i<M;i++){
    //     Shift(Number,N);
    // }
    //OP2
    M%=N;
    int *t=(int*)calloc(M,sizeof(int));
    for(int i=0;i<M;i++){
        scanf("%d",t+i);
    }
    for(int i=0;i<N-M;i++){
        scanf("%d",&Number[i]);
    }
    for(int i=0;i<N;i++){
        Number[N-M+i]=t[i];
    }
    free(t);
    for(int i=0;i<N-1;i++){
        printf("%d ",Number[i]);
    }
    printf("%d\n",Number[N-1]);
    return 0;
}

//gcd(a, b) = gcd(b, a mod b)
int gcd(int a,int b){
    while(b){
        int t=b;
        a=t;
        b=a%b;
    }
    return a;
}

void Shift(int Array[],int N){
    int ArrayHead;
    ArrayHead = Array[0];
    for(int i=0;i<N-1;i++){
        Array[i]=Array[i+1];
    }
    Array[N-1]=ArrayHead;
}