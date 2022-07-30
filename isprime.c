#include <stdio.h>
int main(int args,char** argv){
    int n;
    scanf("%d",&n);
    /*
    isprime
    */
   int flag=1;
   for (int i=2;i<n/2;i++){
    if(n%i==0){
        flag=0;
        break;
    }
   }
   if(flag){
    printf("是素数\n");
   }else{
    printf("不是素数\n");
   }

    
    return 0;
}