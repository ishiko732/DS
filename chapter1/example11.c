#include <stdio.h>

int mul_n(int x,int n){
    int mul=1;
    for (int i=1;i<=n/2;i++){
        mul*=x;
    }
    if(n%2==0){
        // 偶数
        mul=mul*mul;
    }else{
        mul=mul*mul*x;
    }
    return mul;
}

int main(int args,char** argv){
    int x,n;
    x=2;
    n=7;
    printf("%d^%d=%d\n",x,n,mul_n(x,n));
    return 0;
}