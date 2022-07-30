#include <stdio.h>
typedef enum bool{false,true} bool;

bool isPrime(int k){
    int flag=0;
    for (int i=2;i<=k/2;i++){
        if(k%i==0){
            return false;
        }
    }
    return true;
}

int main(int args,char** argv){
    if(isPrime(4)){
        printf("是素数\n");
    }else{
        printf("不是素数\n");
    }
    return 0;
}