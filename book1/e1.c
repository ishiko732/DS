#include <stdio.h>
#include <stdlib.h>

int f(int m,int n){
    if(m==1||n==1)return 1;
    if(m<n) return f(m,m);
    if(m==n) return 1+f(m,n-1);
    return f(m,n-1)+f(m-n,n);
}

int main(){
    printf("%d\n",f(2,1));
    return 0;
}